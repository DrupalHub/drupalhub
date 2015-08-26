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

    // Clean the local storage after the work.
    $this->helper->ClearLocalStorage();

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
    $page = $this->getSession();
    $this->saveScreenshot();
    $text .= sprintf(' Look on the screen shot at %s', $this->screenShotPath);

    print_r($page->getPage()->getHtml());

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
}
