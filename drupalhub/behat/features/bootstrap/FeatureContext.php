<?php

use Behat\Behat\Context\ClosuredContextInterface,
    Behat\Behat\Context\TranslatedContextInterface,
    Behat\Behat\Context\BehatContext,
    Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
    Behat\Gherkin\Node\TableNode;
use Drupal\DrupalExtension\Context\DrupalContext;

/**
 * Features context.
 */
class FeatureContext extends DrupalContext {

  protected $DrupalHubUsers = array();

  /**
   * Initializes context.
   * Every scenario gets its own context object.
   *
   * @param array $parameters context parameters (set them up through behat.yml)
   */
  public function __construct(array $parameters) {
    $this->DrupalHubUsers = $parameters['users'];

  }

  /**
   * @Given /^I should print page$/
   */
  public function iShouldPrintPage() {
    $page = $this->getSession();
    print_r($page->getPage()->getContent());
  }

  /**
   * @Given /^I am logging in as "([^"]*)"$/
   */
  public function iAmLoggingInAs($user) {
    // Check if logged in.
    if ($this->loggedIn()) {
      $this->logout();
    }

    if (empty($this->DrupalHubUsers[$user])) {
      throw new \Exception(sprintf('The user name was not found', $user));
    }

    $this->getSession()->visit($this->locatePath('/user'));
    $element = $this->getSession()->getPage();
    $element->fillField('name', $user);
    $element->fillField('pass', $this->DrupalHubUsers[$user]);
    $submit = $element->findButton($this->getDrupalText('log_in'));
    if (empty($submit)) {
      throw new \Exception(sprintf("No submit button at %s", $this->getSession()->getCurrentUrl()));
    }

    // Log in.
    $submit->click();

    if (!$this->loggedIn()) {
      throw new \Exception(sprintf("Failed to log in as user '%s' with role '%s'", $this->user->name, $this->user->role));
    }
  }

  /**
   * @Given /^I fill in "([^"]*)" with the date format "([^"]*)"$/
   */
  public function iFillInWithTheDateFormat($field, $format) {
    $this->fillField($field, date($format, time()));
  }

  /**
   * @Given /^I sleep for "([^"]*)"$/
   */
  public function iSleepFor($time) {
    sleep($time);
  }

  /**
   * @Given /^I add video to plyalist$/
   */
  public function iAddVideoToPlyalist() {
    $page = $this->getSession();
    $element = $page->getPage()->find('xpath', '//i[@class="fa fa-plus"]');

    if (!$element) {
      throw new \Exception("There are no elements to add to the plyalist");
    }

    $element->click();
  }

  /**
   * @Given /^I should see "([^"]*)" under "([^"]*)"$/
   */
  public function iShouldSeeUnder($content, $selector) {
    $page = $this->getSession();
    $element = $page->getPage()->find('xpath', "//*[contains(@class, '{$selector}') and contains(., '{$content}')]");

    if (empty($element)) {
      throw new PendingException("The requested element was not found in the page.");
    }
  }

  /**
   * @Given /^I fill in the ckeditor "([^"]*)" with "([^"]*)"$/
   */
  public function iFillInTheCkeditorWith($instance, $body) {
    $selenium = $this->getSession()->getDriver();
    $selenium->evaluateScript("CKEDITOR.instances['{$instance}'].setData('{$body}');");
  }
}
