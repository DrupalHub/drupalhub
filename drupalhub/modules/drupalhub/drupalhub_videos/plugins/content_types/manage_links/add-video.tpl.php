<div class="modal fade" id="AddVideo" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only"><?php print t('Close'); ?></span></button>
        <h4 class="modal-title" id="myModalLabel"><?php print t('Add youtube video'); ?></h4>
      </div>
      <div class="modal-body">
        <div class="form-group name">
          <label for="Name"><?php print t('Youtube address: '); ?></label>
          <input type="text" class="form-control" id="url" size="30" placeholder="<?php print t('Youtube link address'); ?>">
        </div>
      </div>
      <div class="result clearfix disabled">
        <div class="image">
          <img />
        </div>

        <div class="information">
          <div class="title"></div>
          <div class="description"></div>
        </div>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-primary"><?php print t('Save'); ?></button>
      </div>
    </div>
  </div>
</div>