<?php if($vote): ?>
<?php print $vote; ?>
<?php endif; ?>
<div><i class="fa fa-clock-o"></i> <?php print $time; ?></div>
<div><i class="fa fa-user"></i> <?php print $author; ?></div>
<?php if($tags): ?>
  <div><i class="fa fa-tags"></i> <div class="tags-links"><?php print $tags; ?></div></div>
<?php endif; ?>
<?php if($follow): ?>
  <div class="follow"><?php print $follow; ?></div>
<?php endif; ?>
