Feature: Testing documentation interactions.

  @javascript
  Scenario: Testing limitation for documentation creation.
    Given I visit "/documentations"
      And I should not see "Add documentation"
     When I logging in as "Utau"
      And I visit "/documentations"
      And I sleep for "10"
      And I capture page
     Then I should see "Add documentation"

  @javascript
  Scenario: Testing limitation for documentation creation.
    Given I logging in as "Utau"
      And I visit "/documentations"
      And I sleep for "10"
      And I click "Add documentation"
      And I fill in "Title" with "Testing documentation title"
      And I fill in the ckeditor "textArea" with "Testing documentation body"
      And I fill in "Title" with "Testing documentation title"
      And I populate the category field with "Drupal 6"
     When I press "Submit"
      And I sleep for "10"
     Then I should see "Testing documentation title"
      And I should see "Testing documentation body"
