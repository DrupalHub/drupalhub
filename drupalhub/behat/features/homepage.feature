Feature: Testing home page

  @api
  Scenario: Testing the home page
    Given I visit "front"
     Then I should see "Help and support"