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

  $edit = strip_tags($fields['edit_comment']->content, 'span');
?>

<div class="comment-wrapper">
  <div class="wrapper-top clearfix">
    <div class="col-md-2 col-xs-12 picture"><?php print $fields['picture']->content; ?></div>
    <div class="col-md-10 col-xs-12 text"><?php print $fields['comment_body']->content; ?></div>
  </div>
  <div class="wrapper-bottom clearfix">
    <div class="col-md-10 metatags">
      <?php print $fields['field_vote']->content; ?>
      <i class="fa fa-clock-o"></i> <?php print $fields['created']->content; ?>
      <i class="fa fa-user"></i> <?php print $fields['name']->content; ?>
    </div>
    <div class="col-md-2 links">
      <?php if(!empty($edit)): ?>
        <i class="fa fa-pencil"></i><?php print $fields['edit_comment']->content; ?>
      <?php endif; ?>
      <?php if(!empty($fields['delete_comment'])): ?>
        <i class="fa fa-trash-o"></i> <?php print $fields['delete_comment']->content; ?>
      <?php endif; ?>
    </div>
  </div>
</div>