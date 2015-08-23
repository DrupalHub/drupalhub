Feature: Sanity check

  @javascript
  Scenario: Check front page
    Given I visit "/"
    Then I should see "Questions"