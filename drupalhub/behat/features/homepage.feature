Feature: Testing home page

  @api
  Scenario: Testing the home page
    Given I should print page
    Given I visit "/"
     Then I should see "Help and support"