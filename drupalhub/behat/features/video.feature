Feature: Testing video section.

  @javascript @now
  Scenario: Testing adding of youtube video.
    Given I am logging in as "ClarkKent"
      And I visit "video"
      And I click "Add video"
      And I fill in "url" with "https://www.youtube.com/watch?v=6FOUqQt3Kg0"
      And I wait for AJAX to finish
      And I should see "Aretha Franklin - Respect [1967] (Original Version)"
      And I should see "Aretha Franklin - Respect"
     When I press "Save"
     Then I should see "The playlist has created successfully"
