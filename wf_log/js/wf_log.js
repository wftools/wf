/**
 * @file
 * WF Log module javascript functions
 */

/**
 * Attaches the colorbox listeners to log entry rows.
 */
(function ($) {
  Drupal.behaviors.wfLog = {
    attach: function (context, settings) {
      $('tr.wf-log-entry', context).click(function() {
        var row = $(this),
        link = $('td.views-field-created a', row)[0].href;

        $.colorbox({
          href: link + '?iframe=true',
          width: "80%",
          height: "80%",
          title: Drupal.t("Changelog"),
          scrolling: true
        });

        // Prevent default anchor event from firing.
        return false;
      });
    }
  };

  Drupal.behaviors.reviewTabs = {
    attach: function () {
      $('#review-tabs a').click(function() {
        var tab = $(this).attr('href');

        $('.tab-container').hide();
        $(tab).show();

      });
    }
  };

})(jQuery);
