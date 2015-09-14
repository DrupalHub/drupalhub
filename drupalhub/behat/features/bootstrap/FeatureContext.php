<?php

use Behat\Gherkin\Node\TableNode;
use Drupal\DrupalExtension\Context\DrupalContext;

require_once 'FeatureHelper.php';

/**
 * Features context.
 */
class FeatureContext extends DrupalContext {

  /**
   * @var FeatureHelper
   */
  public $helper;

  /**
   * {@inheritdoc}
   */
  public function beforeScenario($event) {
    // Set up the browser width.
    $this->getSession()->resizeWindow(1440, 900, 'current');

    $this->helper = new FeatureHelper($this);

    $this->helper->ClearLocalStorage();
    $this->helper->wipeScreenShots();

    parent::beforeScenario($event);
  }

  /**
   * @var String
   *
   * The screen shot path.
   */
  public $screenShotPath;

  /**
   * Overrides the class save screen shoot method.
   */
  public function saveScreenShot($filename = null, $filepath = null) {
    $driver = $this->getSession()->getDriver();
    $screen_shot = $driver->getScreenshot();
    $this->screenShotPath = getcwd() . '/screenshots/' . time() . '.png';

    file_put_contents($this->screenShotPath, $screen_shot);
  }

  /**
   * Throw exception with picture.
   *
   * @param $text
   *   The text. The screen shot image will be added.
   *
   * @throws Exception
   */
  protected function throwException($text) {
    $this->saveScreenshot();
    $text .= sprintf('. Look on the screen shot at %s', $this->screenShotPath);

    throw new \Exception($text);
  }

  /**
   * @Then /^I should see the links:$/
   */
  public function iShouldSeeTheLinks(TableNode $table) {
    foreach ($table->getRows() as $row) {
      try {
        $this->assertSession()->pageTextContains($this->fixStepArgument($row[0]));
      } catch (\Exception $e) {
        $this->throwException(sprintf('The tests did not find the text %s', $row[0]));
      }
    }
  }

  /**
   * @Given /^I sleep for "([^"]*)"$/
   */
  public function iSleepFor($sleep) {
    sleep($sleep);
  }

  /**
   * @Given /^I capture page$/
   */
  public function iCapturePage() {
    $this->saveScreenShot();
  }

  /**
   * @When /^I fill in "([^"]*)" with "([^"]*)" under "([^"]*)"$/
   */
  public function iFillInWithUnder($name, $value, $form_name) {
    $page = $this->getSession();
    $element = $page->getPage()->find('xpath', "//form[@name='{$form_name}']//input[@name='{$name}']");

    if (!$element) {
      $this->throwException(sprintf('The element %s was not fond', $name));
    }

    $element->setValue($value);
  }

  /**
   * @Given /^I logging in as "([^"]*)"$/
   */
  public function iLoggingInAs($username) {
    $token = $this->helper->getAccessToken($username);

    $this->visit($this->getMinkParameter('base_url'));

    // Set up the access token for the user.
    $this->getSession()->evaluateScript("localStorage.setItem('ls.access_token', '{$token}');");
    $this->getSession()->evaluateScript("localStorage.setItem('ls.expire_in', " . strtotime("now + 30 days") . ");");
    $this->visit($this->getMinkParameter('base_url'));
  }

  /**
   * @Then /^I should see "([^"]*)" in the user directive$/
   */
  public function iShouldSeeUnder($text) {
    $xpath = "//span[contains(@class, 'dropdown-toggle') and contains(.,'{$text}')]";
    $element = $this->getSession()->getPage()->find('xpath', $xpath);

    if (!$element) {
      $this->throwException(sprintf('The user name was not found in the user directive.', $xpath));
    }
  }

  /**
    * @Given /^I fill in the ckeditor "([^"]*)" with "([^"]*)"$/
    */
  public function iFillInTheCkeditorWith($instance, $body) {
    $selenium = $this->getSession()->getDriver();
    $selenium->evaluateScript("
      angular.element('#{$instance}').css('visibility', 'visible');
      angular.element('#{$instance}').css('display', 'block');
      CKEDITOR.instances['{$instance}'].setData('{$body}');
    ");
    $this->getSession()->getPage()->fillField($instance, $body);
    $selenium->evaluateScript("
      angular.element('#{$instance}').css('visibility', 'hidden');
      angular.element('#{$instance}').css('display', 'none');
    ");
  }

  /**
   * @When /^I visit the node "([^"]*)"$/
   */
  public function iVisitTheNode($nodeLabel) {
    $node = $this->helper->getNodeInfo($nodeLabel);
    $this->visit($node['type'] . '/' . $node['nid']);
    $this->iSleepFor(5);
  }

  /**
   * @When /^I edit the node "([^"]*)"$/
   */
  public function iEditTheNode($nodeLabel) {
    $node = $this->helper->getNodeInfo($nodeLabel);
    $this->visit($node['type'] . '/' . $node['nid'] . '/edit');
    $this->iSleepFor(5);
  }
}
