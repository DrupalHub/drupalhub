Feature: Testing blog interactions.

  @javascript @now
  Scenario: Testing limitation for blog creation.
    Given I visit "/"
      And I should not see "Create a blog post"
     When I logging in as "Utau"
      And I visit "/"
      And I capture page
     Then I should see "Create a blog post"