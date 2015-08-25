Feature: Sanity check

  @javascript
  Scenario: Check the login process.
    Given I visit "/"
      And I click "Login/Sign in"
     When I fill in "Username" with "admin" under "loginForm"
      And I fill in "Password" with "admin" under "loginForm"
      And I press "submit"
      And I sleep for "5"
      And I should see "admin"
