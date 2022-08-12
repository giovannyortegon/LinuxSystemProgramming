$(document).ready(function () {
  var $scrollTop = $(".scroll-to-top-btn");
  if ($scrollTop.length > 0) {
    $(window).on("scroll", function () {
      if ($(this).scrollTop() > 600) {
        $scrollTop.addClass("visible");
      } else {
        $scrollTop.removeClass("visible");
      }
    });

    $scrollTop.on("click", function (e) {
      e.preventDefault();
      $("html, body")
        .stop()
        .animate(
          {
            scrollTop: $("#IndiceTematico").offset().top,
          },
          1000
        );
    });
  }

  $('.nav-tema-item a[href^="#"]').on("click", function (e) {
    e.preventDefault();

    $(document).off("scroll");

    $("nav a").each(function () {
      $(this).removeClass("active");
    });

    $(this).addClass("active");

    var target = this.hash;

    $target = $(target);
    $("html, body")
      .stop()
      .animate(
        {
          scrollTop: $target.offset().top + 2,
        },
        1000
      );
  });
});