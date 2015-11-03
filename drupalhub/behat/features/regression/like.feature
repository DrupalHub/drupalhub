Feature: Verify a user can like a question.

  @javascript
  Scenario: Testing limitation for blog creation.
    Given I logging in as "Utau"
     When I click "#/question/3"
      And I click "0"
