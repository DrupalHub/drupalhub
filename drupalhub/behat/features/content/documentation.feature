Feature: Testing documentation interactions.

  @javascript @now
  Scenario: Testing limitation for documentation creation.
    Given I visit "/documentations"
      And I should not see "Add documentation"
     When I logging in as "Utau"
      And I visit "/documentations"
     Then I should see "Add documentation"

#  @javascript
#  Scenario: Testing limitation for documentation creation.
#    Given I logging in as "Utau"
#    And I click "Create a documentation post"
#    And I fill in "Title" with "Testing documentation title"
#    And I fill in the ckeditor "textArea" with "Testing documentation body"
#    And I fill in "Title" with "Testing documentation title"
#    When I press "Submit"
#    And I sleep for "10"
#    Then I should see "Testing documentation title"
#    And I should see "Testing documentation body"
#
#  @javascript
#  Scenario: Testing edit of question
#    Given I logging in as "PeterParker"
#    When I visit the node "Testing documentation title"
#    And I should see "Testing documentation title"
#    Then I should not see "Edit"
#
#  @javascript
#  Scenario: Testing edit of question
#    Given I logging in as "Utau"
#    When I visit the node "Testing documentation title"
#    And I should see "Testing documentation title"
#    Then I should see "Edit"
#
#  @javascript
#  Scenario: Testing edit of question
#    Given I logging in as "Utau"
#    And I edit the node "Testing documentation title"
#    And I fill in "Title" with "Edited: Testing documentation title"
#    And I fill in the ckeditor "textArea" with "Edited: Testing documentation body"
## Comment out for now since phatomJS don't populate the field properly.
##     When I press "Submit"
##      And I sleep for "10"
##     Then I should see "Edited: Testing documentation title"
##      And I should see "Edited: Testing documentation body"