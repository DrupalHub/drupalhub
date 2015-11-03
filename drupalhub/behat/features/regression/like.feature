Feature: Verify a user can like a question.

  @javascript @wip
  Scenario: Testing limitation for blog creation.
    Given I logging in as "Utau"
      And I visit "/question/73"
      And I grant a like
     Then I verify the like has granted
