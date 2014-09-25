<div class="modal fade" id="UpdateAbout" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only"><?php print t('Close'); ?></span></button>
        <h4 class="modal-title" id="myModalLabel"><?php print t('Create question'); ?></h4>
      </div>
        <div class="form-group body">
          <label for="Name"><?php print t('About your self: '); ?></label>
          <textarea id="body" class="form-control" placeholder="<?php print t('Write something about your self'); ?>"></textarea>
        </div>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-primary"><?php print t('Save'); ?></button>
      </div>
    </div>
  </div>
</div>