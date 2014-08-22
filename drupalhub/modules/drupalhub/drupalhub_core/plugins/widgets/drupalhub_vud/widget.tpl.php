<?php

/**
 * @file
 * widget.tpl.php
 *
 * UpAndDown widget theme for Vote Up/Down
 * TODO use $show_up_as_link and $show_down_as_link
 */

dpm(get_defined_vars());
?>

<span class="points"><?php print $points; ?></span>

<?php if($show_up_as_link): ?>
  <span class="points">|</span> <i class="fa vote fa-thumbs-o-up"></i>
<? else: ?>
  <span class="points">|</span> <i class="fa vote fa-thumbs-o-down"></i>
<?php endif; ?>