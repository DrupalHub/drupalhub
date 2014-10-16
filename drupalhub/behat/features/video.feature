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
     Then I should see "The video added successfully. Click here"

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
    Scenario: Test the playlist form validation.
      Given I am logging in as "ClarkKent"
        And I visit "video/playlists"
        And I click "Create a new playlist"
       When I press "Save"
       Then I should see "Please fill in the name."
        And I should see "Please insert videos."
        And I should see "Please insert description."

  @javascript
    Scenario: Verify creation of playlist.
    Given I am logging in as "ClarkKent"
      And I visit "video/playlists"
      And I click "Create a new playlist"
      And I fill in "name" with "Dummy playlist"
      And I fill in "playlist-search" with "Programming With Anthony"
      And I wait for AJAX to finish
      And I add video to plyalist
      And I fill in "description" with "Dummy one"
     When I press "Save"
      And I wait for AJAX to finish
     Then I should see "The playlist has created successfully"

  @javascript
  Scenario: Editing a playlist.
    Given I am logging in as "ClarkKent"
      And I visit "video/playlists"
      And I click "Edit"
      And I wait for AJAX to finish
      And I fill in "playlist-search" with "Programming With Anthony"
      And I wait for AJAX to finish
      And I add video to plyalist
     When I press "Save"
     Then I should see "The playlist has created successfully"
      And I should see "2" under "videos"
      And I reload the page
      And I should see "2" under "videos"

  @javascript
  Scenario: Deleting a playlist.
    Given I am logging in as "ClarkKent"
      And I visit "video/playlists"
     When I click "Delete"
      And I wait for AJAX to finish
     Then I should not see "Dummy playlist"
      And I reload the page
      And I should not see "Dummy playlist"
