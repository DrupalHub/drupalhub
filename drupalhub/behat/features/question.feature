Feature: Testing the question.

  @javascript
  Scenario: Testing the form validation of the question creation.
    Given I visit "/"
     When I click "Ask question"
      And I wait for AJAX to finish
     When I should see "Create question"
      And I press "Save"
     Then I should see "Title field is a required field."
      And I should see "The body is a required field."

  @javascript
  Scenario: Testing the creation of the form.
    Given I am logging in as "ClarkKent"
      And I click "Ask question"
      And I wait for AJAX to finish
      And I should see "Create question"
     When I fill in "title" with "Testing"
      And I fill in the ckeditor "body" with "Body"
      And I press "Save"
      And I wait for AJAX to finish
     Then I sleep for "1.5"
      And I should see "Testing"
      And I should see "Body"
