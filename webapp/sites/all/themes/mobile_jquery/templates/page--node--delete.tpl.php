<?php $page['attributes_array']['page']['data-role'] = 'dialog'; ?>
<div <?php print drupal_attributes($page['attributes_array']['page']); ?>>
    <div class="header" <?php print drupal_attributes($page['attributes_array']['header']); ?>>
      <?php if ($site_name): ?>
        <h1 class="site-name"><?php print $site_name; ?></h1>
      <?php elseif ($logo): ?>
        <h1>
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </h1>
      <?php endif; ?>
		</div> <!-- /#header -->


    <div class="main-content" <?php print drupal_attributes($page['attributes_array']['content']); ?>>	      
			    <?php print $messages; ?>	
	        <?php if ($page['highlighted']): ?><div class="highlighted"><?php print render($page['highlighted']); ?></div><?php endif; ?>
	        <?php print render($title_prefix); ?>
	        <?php if ($title): ?><h2 class="title" class="page-title"><?php print $title; ?></h2><?php endif; ?>
	        <?php print render($title_suffix); ?>
	        <?php print render($page['help']); ?>
	        <?php print render($page['content']); ?>
    </div>
</div> <!-- /#page -->
