Feature: Testing the event section.

  @javascript
  Scenario: Testing validation of the form.
    Given I am logging in as "ClarkKent"
      And I visit "calendar"
     When I click "Create event"
      And I wait for AJAX to finish
      And I check the box "Add end date"
     When I press "Save"
     Then I should see "This is a required field."
      And I should see "You need to set a date for the event."
    
  @javascript @now
  Scenario: Testing event creation.
    Given I am logging in as "ClarkKent"
      And I visit "calendar"
      And I click "Create event"
      And I wait for AJAX to finish
      And I fill in "title" with "Dummy event"
      And I fill in "body" with "Dummy event content"
      And I fill in "date" with the date format "d/m/Y"
     When I press "Save"
      And I wait for AJAX to finish
     Then I should see "The event has created successfully. See your event"
      And I click "See your event"
      And I should see "Dummy event"
      And I should see "Dummy event content"
