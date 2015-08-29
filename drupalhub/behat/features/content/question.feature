Feature: Testing the question workflow.

  @javascript @now
  Scenario: Testing a user can post a question.
    Given I logging in as "ClarkKent"
      And I click "Ask a question"
      And I populate "Title" with "foo"
      And I capture page
      And I fill in the ckeditor "textArea" with "Testing question body"
     When I press "Submit"
      And I sleep for "10"
      And I capture page
#     Then I should see "Testing question title"
      And I should see "Testing question body"