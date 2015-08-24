Feature: Sanity check

  @javascript @now
  Scenario: Check the login process.
    Given I visit "/"
      And I click "Login/Sign in"
     When I fill in "Username" with "admin" under "loginForm"
      And I fill in "Password" with "admin" under "loginForm"
      And I press "submit"
      And I should see "admin"