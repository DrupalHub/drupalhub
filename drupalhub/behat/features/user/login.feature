Feature: Check login functionallity. 

  @javascript
  Scenario: Check the user can login.
    Given I visit "/"
      And I click "Login/Sign in"
     When I fill in "Username" with "ClarkKent" under "loginForm"
      And I fill in "Password" with "LouisLane" under "loginForm"
      And I press "submit"
      And I sleep for "5"
      And I should see "admin"

  @javascript
  Scenario: Check the user can't login with bad credentials.
    Given I visit "/"
      And I click "Login/Sign in"
     When I fill in "Username" with "ClarkKent" under "loginForm"
      And I fill in "Password" with "1234" under "loginForm"
      And I press "submit"
      And I sleep for "5"
     Then I should see "The username/password are wrong."
