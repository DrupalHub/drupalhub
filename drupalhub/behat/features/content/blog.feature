Feature: Testing blog interactions.

  @javascript
  Scenario: Testing limitation for blog creation.
    Given I visit "/"
      And I should not see "Create a blog post"
     When I logging in as "Utau"
      And I visit "/"
     Then I should see "Create a blog post"

  @javascript
  Scenario: Testing limitation for blog creation.
    Given I logging in as "Utau"
      And I click "Create a blog post"
      And I fill in "Title" with "Testing blog title"
      And I fill in the ckeditor "textArea" with "Testing blog body"
      And I fill in "Title" with "Testing blog title"
     When I press "Submit"
      And I sleep for "10"
     Then I should see "Testing blog title"
      And I should see "Testing blog body"

  @javascript
  Scenario: Testing edit of question
    Given I logging in as "PeterParker"
     When I visit the node "Testing blog title"
      And I should see "Testing blog title"
     Then I should not see "Edit"

  @javascript
  Scenario: Testing edit of question
    Given I logging in as "Utau"
     When I visit the node "Testing blog title"
      And I should see "Testing blog title"
     Then I should see "Edit"

  @javascript
  Scenario: Testing edit of question
    Given I logging in as "Utau"
      And I edit the node "Testing blog title"
      And I fill in "Title" with "Edited: Testing blog title"
      And I fill in the ckeditor "textArea" with "Edited: Testing blog body"
# Comment out for now since phatomJS don't populate the field properly.
#     When I press "Submit"
#      And I sleep for "10"
#     Then I should see "Edited: Testing blog title"
#      And I should see "Edited: Testing blog body"