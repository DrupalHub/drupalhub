Feature: Testing home page

  @api
  Scenario: Testing the home page
    Given I visit "front"
      And I should print page
     Then I should see "Help and support"