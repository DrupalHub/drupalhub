Feature: Sanity check

  @javascript
  Scenario: Check front page
    Given I visit "/"
    Given I should see "a"
    Then I should see the links:
      | DrupalHub     |
      | Events        |
      | Videos        |
      | Documentation |
      | Search        |
      | Social Up!    |
      | Login/Sign in |
      | Events        |
      | Last videos   |
      | Blogs         |
