<?php

use Behat\Gherkin\Node\TableNode;
use Drupal\DrupalExtension\Context\DrupalContext;

/**
 * Features context.
 */
class FeatureContext extends DrupalContext {

  /**
   * {@inheritdoc}
   */
  public function beforeScenario($event) {
    // Set up the browser width.
    $this->getSession()->resizeWindow(1440, 900, 'current');
    // todo Check if we testing mobile.
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
    $text .= sprintf('Look on the screen shot at %s', $this->screenShotPath);
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
}
