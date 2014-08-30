<?php
  // Clean the link from span se we could if there any text.
  $edit = strip_tags($fields['edit_node']->content, 'span');
?>
<div class="row blogs-wrapper clearfix">
  <div class="top-wrapper">
    <div class="col-md-12">
      <h1><?php print $fields['title']->content; ?></h1>
      <?php print $fields['body']->content; ?>
    </div>
  </div>
  <div class="bottom-wrapper">
    <div class="row">
      <div class="col-lg-10 col-md-9 col-sm-8">
        <?php print $fields['time_name_tags']->content; ?>
      </div>
      <div class="col-lg-2 col-md-3 col-sm-4">
        <?php if(!empty($edit)): ?>
          <i class="fa fa-pencil"></i><?php print $fields['edit_node']->content; ?>
        <?php endif; ?>
        <?php if(!empty($fields['delete_node'])): ?>
          <i class="fa fa-trash-o"></i> <?php print $fields['delete_node']->content; ?>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>