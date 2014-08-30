<?php
/**
 * @file
 * template override for the tagged nodes - blogs and questions. I copied the
 * two content from the other template since it was the most easy thing to do.
 */

  // Clean the field vote from any html so we have only the number of votes.
  $vote = strip_tags($fields['field_vote']->content, 'span div a');

  // Clean the link from span se we could if there any text.
  $edit = strip_tags($fields['edit_node']->content, 'span');
?>
<?php if ($fields['type']->raw == 'blog'): ?>
<div class="row blogs-wrapper clearfix">
  <div class="top-wrapper">
    <div class="col-md-12">
      <h1><?php print $fields['title']->content; ?></h1>
      <?php print $fields['body']->content; ?>
    </div>
  </div>
  <div class="col-md-12 bottom-wrapper clearfix">
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
<?php else: ?>
<div class="row question-wrapper clearfix">
  <div class="col-md-12 top-wrapper clearfix">
    <div class="col-md-1 icons"><span><?php print $fields['field_count']->content; ?></span><i class="fa fa-eye"></i></div>
    <div class="col-md-1 icons"><span><?php print $fields['comment_count']->content; ?></span><i class="fa fa-comment-o"></i></div>
    <div class="col-md-1 icons"><span><?php print $vote; ?></span><i class="fa fa-thumbs-o-up"></i></div>
    <div class="col-md-9"><?php print $fields['title']->content; ?><?php print $fields['body']->content; ?></div>
  </div>
  <div class="col-md-12 bottom-wrapper clearfix">
    <div class="col-md-10">
      <?php print $fields['time_name_tags']->content; ?>
    </div>

    <div class="col-md-2">
      <?php if(!empty($edit)): ?>
        <i class="fa fa-pencil"></i><?php print $fields['edit_node']->content; ?>
      <?php endif; ?>
      <?php if(!empty($fields['delete_node'])): ?>
        <i class="fa fa-trash-o"></i> <?php print $fields['delete_node']->content; ?>
      <?php endif; ?>
    </div>
  </div>
</div>
<?php endif; ?>