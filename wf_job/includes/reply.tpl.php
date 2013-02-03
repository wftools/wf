<li id="reply-<?php print $reply->id ?>" class="<?php print $classes ?>">
  <div class="reply-meta">
    <div class="date"><?php print $date; ?></div>
    <div class="time"><?php print $time; ?></div>
    <div class="reply-links"><?php print render($links) ?></div>
  </div>
  <h4 class="reply-title"><?php print $title; ?></h4>
  <div class="reply-author">Posted by <?php print $author; ?></div>
  <div class="reply-body">
    <?php print render($content) ?>
  </div>
  <div class="clear-fix"></div>
</li>
