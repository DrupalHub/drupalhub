<?php if($vote): ?>
  <?php print $vote; ?>
<?php endif; ?>
<i class="fa fa-clock-o"></i> <?php print $time; ?>
<i class="fa fa-user"></i> <?php print $author; ?>
<?php if($follow): ?>
  <?php print $follow; ?>
<?php endif; ?>
<?php if($tags): ?>
  <i class="fa fa-tags"></i> <div class="tags-links"><?php print $tags; ?></div>
<?php endif; ?>
