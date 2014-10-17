<div class="modal fade" id="NewEvent" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only"><?php print t('Close'); ?></span></button>
        <h4 class="modal-title" id="myModalLabel"><?php print t('Create event'); ?></h4>
      </div>
      <div class="modal-body">
        <div class="errors">
        </div>

        <div class="success">
          <?php print t('The event has created successfully. <a href="@url">See your event</a> or wait a second'); ?>
        </div>

        <div class="form-group title">
          <label for="Name"><?php print t('Title'); ?></label>
          <input type="text" class="form-control" id="title" placeholder="<?php print t('Event title'); ?>">
        </div>

        <div class="form-group body">
          <label for="Name"><?php print t('Description'); ?></label>
          <textarea id="body" class="form-control" placeholder="<?php print t('Short description about the event'); ?>"></textarea>
        </div>

        <div class="form-group">
          <label for="Name"><?php print t('Date'); ?></label>
          <div class='input-group date' id='StartDate'>
            <input type='text' data-date-format="DD/MM/YYYY HH:mm" id="date" placeholder="<?php print t('Set start date'); ?>" class="form-control" />
            <span class="input-group-addon"><span class="glyphicon glyphicon-calendar"></span></span>
          </div>
        </div>

        <div class="checkbox">
          <label>
            <input type="checkbox" id="end_date_on"> <?php print t('Add end date'); ?>
          </label>
        </div>

        <div class="form-group end_date disabled">
          <div class="form-group">
            <label for="Name"><?php print t('End date'); ?></label>
            <div class='input-group date' id='EndDate'>
              <input type='text' id="end_date" data-date-format="DD/MM/YYYY HH:mm" placeholder="<?php print t('Set end date'); ?>" class="form-control" />
              <span class="input-group-addon"><span class="glyphicon glyphicon-calendar"></span></span>
            </div>
          </div>
        </div>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-primary"><?php print t('Save'); ?></button>
      </div>
    </div>
  </div>
</div>
