<?php

/**
 * @file
 * widget.tpl.php
 *
 * UpAndDown widget theme for Vote Up/Down
 * TODO use $show_up_as_link and $show_down_as_link
 */
?>

<div class="vud-widget vud-widget-upanddown clearfix" id="<?php print $id; ?>">
  <span class="points"><?php print $points; ?></span>

  <?php if($show_up_as_link): ?>
    <span class="points">|</span> <a href="<?php print $link_up; ?>" class="<?php print $link_class_up; ?>"><i class="fa vote fa-thumbs-o-up"></i></a>
  <? else: ?>
    <span class="points">|</span> <a href="<?php print $link_down; ?>" class="<?php print $link_class_down; ?>"><i class="fa vote fa-thumbs-o-down"></i></a>
  <?php endif; ?>
</div>
