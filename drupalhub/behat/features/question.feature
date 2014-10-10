Feature: Testing the question

  @javascript
  Scenario: Testing the form validation of the question creation.
    Given I visit "/"
     When I click "Ask question"
      And I wait for AJAX to finish
     When I should see "Create question"
      And I press "Save"
     Then I should see "The title field is required."
      And I should see "The body field is required."

  @javascript
  Scenario: Testing the creation of the form.
    Given I am logging in as "admin"
      And I click "Ask question"
      And I wait for AJAX to finish
      And I should see "Create question"
     When I fill in "title" with "Testing"
      And I fill in "body" with "Body"
      And I press "Save"
      And I wait for AJAX to finish
      And I should see "The question has created successfully. Visit the question"
     Then I click "Visit the question"
      And I should see "Testing"
      And I should see "Body"

