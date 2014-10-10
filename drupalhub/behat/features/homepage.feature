Feature: Testing home page

  @javascript
  Scenario: Testing the home page
    Given I visit "/"
      And I should see "Help and support"
     When I click "Ask question"
      And I wait for AJAX to finish
      And I should see "Create question"
      And I press "Save"
     Then I should see "The title field is required."
      And I should see "The body field is required."
