Feature: Testing the question workflow.

  @javascript
  Scenario: Testing a user can post a question.
    Given I logging in as "ClarkKent"
      And I click "Ask a question"
      And I fill in "Title" with "Testing question title"
      And I fill in the ckeditor "textArea" with "Testing question body"
      And I fill in "Title" with "Testing question title"
     When I press "Submit"
      And I sleep for "10"
     Then I should see "Testing question title"
      And I should see "Testing question body"

  @javascript @now
  Scenario: Testing edit of question
    Given I logging in as "PeterParker"
     When I visit the node "Testing question title"
      And I should see "Testing question title"
     Then I should not see "Edit"