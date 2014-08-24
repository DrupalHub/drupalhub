<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

  // Clean the field vote from any html so we have only the number of votes.
  $vote = strip_tags($fields['field_vote']->content, 'span div a');

  // Clean the link from span se we could if there any text.
  $edit = strip_tags($fields['edit_node']->content, 'span');
?>

<div class="row question-wrapper clearfix">
  <div class="col-md-12 top-wrapper clearfix">
    <div class="col-md-1 icons"><span><?php print $fields['field_count']->content; ?></span><i class="fa fa-eye"></i></div>
    <div class="col-md-1 icons"><span><?php print $fields['comment_count']->content; ?></span><i class="fa fa-comment-o"></i></div>
    <div class="col-md-1 icons"><span><?php print $vote; ?></span><i class="fa fa-thumbs-o-up"></i></div>
    <div class="col-md-9"><?php print $fields['title']->content; ?><?php print $fields['body']->content; ?></div>
  </div>
  <div class="col-md-12 bottom-wrapper clearfix">
    <div class="col-md-10">
      <span class="time"><i class="fa fa-clock-o"></i> <?php print $fields['created']->content; ?></span>
      <span class="name"><i class="fa fa-user"></i> <?php print $fields['name']->content; ?></span>
      <span class="tags"><i class="fa fa-tags"></i> <?php print $fields['field_tags']->content; ?></span>
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
