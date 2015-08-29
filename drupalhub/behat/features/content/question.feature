Feature: Testing the question workflow.

  @javascript @now
  Scenario: Testing a user can post a question.
    Given I logging in as "ClarkKent"
      And I click "Ask a question"
      And I fill in "Title" with "Testing question title"
      And I fill in "Question" with "Testing question body"
      And I capture page