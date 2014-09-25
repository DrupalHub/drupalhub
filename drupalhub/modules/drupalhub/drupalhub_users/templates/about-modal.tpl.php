<div class="modal fade" id="UpdateAbout" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only"><?php print t('Close'); ?></span></button>
        <h4 class="modal-title" id="myModalLabel"><?php print t('Information about your self'); ?></h4>
      </div>
      <div class="modal-body">
        <div class="form-group about">
          <label for="Name"><?php print t('About your self: '); ?></label>
          <textarea id="about" class="form-control" placeholder="<?php print t('Write something about your self'); ?>"></textarea>
        </div>
      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-primary"><?php print t('Save'); ?></button>
        <div class="passed disabled"><i class="fa fa-thumbs-up"></i> <span><?php print t('The about field has updated successfully. After closing the dispaly will change'); ?></span></div>
      </div>
    </div>
  </div>
</div>