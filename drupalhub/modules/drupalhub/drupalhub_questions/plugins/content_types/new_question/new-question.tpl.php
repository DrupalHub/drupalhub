<div class="modal fade" id="AddQuestion" tabindex="-1" role="dialog" aria-labelledby="myModalLabel" aria-hidden="true">
  <div class="modal-dialog">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal"><span aria-hidden="true">&times;</span><span class="sr-only"><?php print t('Close'); ?></span></button>
        <h4 class="modal-title" id="myModalLabel"><?php print t('Create question'); ?></h4>
      </div>
      <div class="modal-body">
        <div class="form-group title">
          <label for="Name"><?php print t('Title: '); ?></label>
          <input type="text" class="form-control" id="title" placeholder="<?php print t('Ask question'); ?>">
        </div>

        <div class="form-group body">
          <label for="Name"><?php print t('Question: '); ?></label>
          <textarea id="body" class="form-control" placeholder="<?php print t('Ask your question'); ?>"></textarea>
        </div>

        <div class="form-group tags">
          <label for="Name"><?php print t('Tags: '); ?></label>
          <div class="input-group">
            <input type="text" class="form-control" id="tags" placeholder="<?php print t('Add tags for the question'); ?>">
            <span class="input-group-addon"><i class="fa fa-refresh"></i></span>
          </div>
        </div>

      </div>
      <div class="modal-footer">
        <button type="button" class="btn btn-primary"><?php print t('Save'); ?></button>
        <div class="passed disabled"><i class="fa fa-thumbs-up"></i> <span><?php print t('The question has created successfully. <a href="@url">Visit the question</a>'); ?></span></div>
      </div>
    </div>
  </div>
</div>