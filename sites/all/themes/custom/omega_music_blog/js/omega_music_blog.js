(function ($) {
  Drupal.behaviors.omegaMusicBlog = {
    attach: function (context, settings) {
      // Expand status body field on focus.
      var bodyField = $('#block-formblock-status .field-name-field-body textarea', context);
      var defaultValue = bodyField.val();
      bodyField.focus(function() {
        $(this).animate({'rows':'5'}, 100);
      }).blur(function() {
        if ($(this).val() == defaultValue) {
          $(this).animate({'rows':'1'}, 100);
        }
      });
      // Form submit hover.
      var submit = $('.form-submit');
      submit.hover(function() {
        $(this).animate({'backgroundColor': '#d1344e'}, 100);
      }, function() {
        $(this).animate({'backgroundColor': '#525252'}, 'fast');
      });
    }
  };
})(jQuery);
