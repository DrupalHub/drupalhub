Feature: Testing video section.

  @javascript
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

  @javascript
  Scenario: Verify user can't add the same youtube again.
    Given I am logging in as "ClarkKent"
      And I visit "video"
      And I click "Add video"
      And I fill in "url" with "https://www.youtube.com/watch?v=6FOUqQt3Kg0"
      And I wait for AJAX to finish
      And I should see "Aretha Franklin - Respect [1967] (Original Version)"
      And I should see "Aretha Franklin - Respect"
     When I press "Save"
     Then I should see "There is already a video with this youtube address: Aretha Franklin - Respect [1967] (Original Version)."

  @javascript
    Scenario: Testing the playlist form validation.
      Given I am logging in as "ClarkKent"
        And I visit "video/playlists"
        And I click "Create a new playlist"
       When I press "Save"
       Then I should see "Please fill in the name."
        And I should see "Please insert videos."
        And I should see "Please insert description."
