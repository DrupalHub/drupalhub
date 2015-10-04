Feature: Sanity check

  @javascript
  Scenario: Check front page
    Given I visit "/"
    Then I should see the links:
      | DrupalHub     |
      | Events        |
      | Videos        |
      | Documentation |
      | Search        |
      | Social Up!    |
      | Login/Sign in |
      | Events        |
      | Videos        |
      | Blogs         |

  @javascript
  Scenario: Testing the user login step.
    Given I logging in as "ClarkKent"
     When I visit "/"
     Then I should see "ClarkKent" in the user directive
