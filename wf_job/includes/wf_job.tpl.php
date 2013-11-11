<?php
/**
 * @file
 * WF Job view template file.
 */
?>

<h2><?php print $elements['#job']->title; ?></h2>
<dl>
  <dt>ID: </dt>
  <dd><?php print $elements['#job']->jid; ?></dd>

  <dt>Reference: </dt>
  <dd><?php print $elements['#job']->reference; ?></dd>

  <dt>Details: </dt>
  <dd>
    <div>
    <?php print $elements['#job']->details; ?>
    </div>
  </dd>

  <dt>Owner: </dt>
  <dd><?php print $elements['owner_name']; ?></dd>

  <dt>Assigned: </dt>
  <dd><?php print $elements['assigned_name']; ?></dd>

  <dt>Created: </dt>
  <dd><?php print $elements['created_date']; ?></dd>

</dl>

<?php foreach ($elements as $element): ?>
  <?php if (is_array($element) && !empty($element['#theme']) && 'field' == $element['#theme']): ?>
    <?php print drupal_render($element); ?>
  <?php endif; ?>
<?php endforeach; ?>
