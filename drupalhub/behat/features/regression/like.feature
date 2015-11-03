Feature: Verify a user can like a question.

  @javascript @now
  Scenario: Testing limitation for blog creation.
    Given I logging in as "Utau"
     When I click "Search inside title and body"
      And I grant a like
     Then I verify the like has granted
