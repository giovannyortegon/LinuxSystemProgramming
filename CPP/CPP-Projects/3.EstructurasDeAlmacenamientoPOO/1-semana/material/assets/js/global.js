// Base route
const baseRoutes = 'page';

$(document).ready(() => {
  const functionModule = {
    showContent() {
      //if (this.slug == 'glosario' || this.slug == 'glossary') { renderGlossary(this.slug); } else { renderContent(this.slug); }
      renderContent(this.slug);
    },
    anchor() {
      //if (this.slug == 'glosario' || this.slug == 'glossary') { renderGlossary(this.slug); } else { renderContent(this.slug, this.anchor); }
      renderContent(this.slug, this.anchor);
    }
  };
    // Write ur urls here

  // Base route
  $.routes.add(`${baseRoutes}/{ slug }#{ anchor }`, 'anchor', functionModule.anchor);
  $.routes.add(`${baseRoutes}/{ slug }`, 'path', functionModule.showContent);
});

var menu_main_li = "";
var dataGlobal;
var dataMenuMain;

function getRandomInt(min, max) {
    return Math.floor(Math.random() * (max - min)) + min;
}

async function loadJSON(url) {
    const res = await fetch(url);
    return await res.json();
}

function setupConfig(data) {
    //document.getElementById('curso-titulo-componente').textContent = data.programaFormacion;
    //document.title = data.tituloComponente;
}

function crearMenuMain(menu) {

    menu.forEach(function (button) {
        let idTag = '';
        let dataAnchor = '';
        var selectClass = 'no-anchor';
 
        if (button.id != undefined && button.id > 0) {
            idTag = button.id
        }

        if (button.slug == "external" || button.slug == "externo" || button.slug == "pdf") {
            menu_main_li = menu_main_li + '<li class="menu-main__item"><a id="' + idTag + '" class="menu-main__link" href="' + button.path + '"><span class="menu-main__texto">' + button.title + '</span><span class="menu-main__icono"><i class="' + button.icon + '"></i></span></a></li>';
        } else {
            if (button.anchor != undefined && button.anchor.length > 0) {
                selectClass = 'routerAnchor';
                dataAnchor = 'data-anchor="' + button.anchor + '"';
            } else {
                sessionStorage.setItem(button.slug, JSON.stringify(button));
            }



            menu_main_li = menu_main_li + '<li class="menu-main__item"><a id="' + idTag + '" class="menu-main__link is-content ' + selectClass + '" data-route="' + button.slug + '" ' + dataAnchor + '><span class="menu-main__texto">' + button.title + '</span><span class="menu-main__icono"><i class="' + button.icon + '"></i></span></a></li>';
        }
        if (button.submenu && button.submenu.length != 0) {
            menu_main_li = menu_main_li + '<ul class="menu-main submenu">';
            crearMenuMain(button.submenu)
            menu_main_li = menu_main_li + '</ul>';
        }
    });

}

function renderMenuSecondary(data) {

    let menu_secondary = document.getElementById("menuSecondary");

    data.forEach(function (button, i) {

        sessionStorage.setItem(button.slug, JSON.stringify(button));

        let htmlExtra;

        if (button.slug == "external" || button.slug == "externo" || button.slug == "pdf") {
            htmlExtra = '<li class="menu-secondary__item"><a class="menu-secondary__link " href="' + button.path + '" target="_blank"><i class="' + button.icon + '"></i><span class="menu-secondary__texto">' + button.title + '</span></a></li>';
        } else {
            htmlExtra = '<li class="menu-secondary__item"><a class="menu-secondary__link" data-route="' + button.slug + '"><i class="' + button.icon + '"></i><span class="menu-secondary__texto">' + button.title + '</span></a></li>';
        }

        menu_secondary.insertAdjacentHTML('beforeend', htmlExtra);

        document.getElementsByClassName('menu-secondary__link')[i].addEventListener('click', function () {

            if (button.slug != "external" && button.slug != "externo" && button.slug != "pdf") {
                $.routes.find('path').routeTo({ slug: this.getAttribute("data-route") });
                $('.menu-main__link--active').removeClass('menu-main__link--active');
                $('.menu-secondary__link--active').removeClass('menu-secondary__link--active');
                $(this).addClass('menu-secondary__link--active');

                //$('#page-main-header').show();
                //document.getElementById('curso-titulo-tema').textContent = $(this).find('.menu-secondary__texto').html();
            }

        });
    });
}

function renderMenuMain(data) {

    let menu_main_ul = document.getElementById("menuMain");
    crearMenuMain(data);
    menu_main_ul.insertAdjacentHTML('beforeend', menu_main_li);

    let menu_main__link = document.getElementsByClassName('is-content');

    Array.from(menu_main__link).forEach(function (button) {

        button.addEventListener('click', function () {
            let route = button.getAttribute("data-route");
            $.routes.find('path').routeTo({ slug: route });

            let anchor = button.getAttribute("data-anchor");

            //$('#page-main-header').hide();

            $('.menu-main__link--active').removeClass('menu-main__link--active');
            $('.menu-secondary__link--active').removeClass('menu-secondary__link--active');
            $(this).addClass('menu-main__link--active');
            //document.getElementById('curso-titulo-tema').textContent = $(this).find('.menu-main__texto').html();

        });

    });

    let verticalNavbarAnchor = document.getElementsByClassName("routerAnchor");
    Array.from(verticalNavbarAnchor).forEach(function (button) {
        button.addEventListener("click", function (e) {
  
            let route = button.getAttribute("data-route");
            let anchor = button.getAttribute("data-anchor");
            $.routes.find("anchor").routeTo({ slug: route, anchor: anchor });

            //$('#page-main-header').hide();
            $('.menu-main__link--active').removeClass('menu-main__link--active');
            $('.menu-secondary__link--active').removeClass('menu-secondary__link--active');
            $(this).addClass('menu-main__link--active');

        });
    });    
}

async function renderGlossary(slug) {

    let item = sessionStorage.getItem(slug);

    contentObject = JSON.parse(item);

    let mainContent = document.getElementById('mainContent');

    mainContent.textContent = "";

    await loadJSON(contentObject.path).then(data => {

        let htmlGlossary = '<div class="container"><div id="row" class="content"><div class="col-12">';

        data.forEach(function (letter) {
            htmlGlossary += '<table class="glossary"><thead><tr><th scope="col">' + letter.letter + '</th></tr></thead><tbody>';
            letter.terms.forEach(function (term) { htmlGlossary += '<tr><td class="title">' + term.title + '</td><td>' + term.desciption + '</td></tr>'; });
            htmlGlossary += '</tbody></table>';
        });
        htmlGlossary += '</div></div></div>';

        mainContent.innerHTML = htmlGlossary;

    });

}

function renderContent(slug, anchor) {
    
    var viewportWidth = window.innerWidth || document.documentElement.clientWidth;
    if (viewportWidth < 575) {
        $('.page-main-aside__close').trigger('click');
    }
    let item = sessionStorage.getItem(slug);

    if (item) {
        contentObject = JSON.parse(item);
        if (contentObject.path.length > 0) {

            fetch(contentObject.path).then(res => { return res.text(); })
                .then(data => {
                    document.getElementById('mainContent').innerHTML = data;
                    if (anchor != undefined && anchor.length > 0) {
                        $('body,html').stop(true, true).animate({ scrollTop: $('#' + anchor).offset().top - $('.page-topbar').height()}, 1000);
                    } else {
                        if (slug != "glosario" && slug != "material-complementario" && slug != "referencias") {
                            //console.log(slug)
                            refreshControlPage(slug);
                        }
                        $('body,html').stop(true, true).animate({ scrollTop: 0 }, 1000);
                    }
                });

            //document.getElementById('curso-titulo-componente').textContent = dataGlobal.tituloComponente;

        } else {
            document.getElementsByClassName('menu-main__link')[0].click();
            console.log("path no declarado");
        }
    } else {
        document.getElementsByClassName('menu-main__link')[0].click();
        console.log("Slug no encontrado, revisar carpeta de contenido o json de configuración.");
    }



}

function refreshControlPage(actualHash) {
    let navItems = Array.from(document.getElementsByClassName('no-anchor'));
    let navItemIndex = navItems.findIndex((element) => element.getAttribute("data-route") == actualHash);
    (navItemIndex == 0) ? document.getElementById('back').removeAttribute('href'): document.getElementById('back').setAttribute('href', navItems[navItemIndex - 1].getAttribute('data-route'));
    (navItemIndex == (navItems.length - 1)) ? document.getElementById('next').removeAttribute('href'): document.getElementById('next').setAttribute('href', navItems[navItemIndex + 1].getAttribute('data-route'));
}

async function initContent() {

    let navItems = Array.from(document.getElementsByClassName('is-content'));

    if (!(window.location.hash[window.location.hash.length - 1] == '/')) {
        window.location.hash = window.location.hash + '/';  
    }

    if (window.location.hash.length > 2) {
        baseRoutesLength = baseRoutes.length + 2; // length plus # and /
        slug = window.location.hash.substr(baseRoutesLength, window.location.hash.length - (baseRoutesLength + 1));
        let index = navItems.findIndex((element) => element.getAttribute("data-route") == slug);
        if (index != -1) {
            navItems[index].click();
            //if (this.slug == "glosario" || this.slug == "glossary") { renderGlossary(slug); } else { renderContent(slug); }
            renderContent(slug);
        } else {
            navItems[0].click();
            console.log("Render initial: Contenido del hash no encontrado, json de configuración.");
        }
    } else {
        navItems[0].click();
    }
}

document.addEventListener("DOMContentLoaded", async function () {

    if ($("#page-main").length) {

        //$('#page-main-header').hide();

        /*await loadJSON('config/global.json').then(data => {
            dataGlobal = data; setupConfig(data);
        });*/

        await loadJSON('config/menuMain.json').then(data => {
            dataMenuMain = data;
            renderMenuMain(data);
        });

        await loadJSON('config/menuSecondary.json').then(data => {
            if (data.length > 0) {
                renderMenuSecondary(data);
            }
        });

        //Esta función indica que contenido cargar primero
        initContent();

        $(".page-control-link").on("click", function (e) {
            e.preventDefault();
            var hashPageControl = $(this).attr("href");

            $('.no-anchor').each(function(index, element) {
                if ($(element).data('route') == hashPageControl ) {

                    $.routes.find('path').routeTo({ slug: hashPageControl });

                    //$('#page-main-header').hide();
                    
                    $('.menu-main__link--active').removeClass('menu-main__link--active');
                    $('.menu-secondary__link--active').removeClass('menu-secondary__link--active');
                    $(this).addClass('menu-main__link--active');
                    //document.getElementById('curso-titulo-tema').textContent = $(element).find('.menu-main__texto').html();

                }
            })

        });


    }

});

/*------------------------
INICIAMOS WOW
-------------------------*/
new WOW().init();

$(function () {

    //pagemap(document.querySelector("#map"));

    var viewportWidth = window.innerWidth || document.documentElement.clientWidth;
    if (viewportWidth < 575) {
        $("#curso-topbar__nav").removeClass("show");
    } 

    $(".nav-tema-item__titulo, .nav-tema-item__btn").hover(function () {
        $(this).closest('.row').addClass('tema-activo');
    }, function () {
        $(this).closest('.row').removeClass('tema-activo');
    });

    //Menu responsive
    $(".btn-menu-responsive").on('click', function(e) {
        $(this).toggleClass('active');
    });

    //Tabla de contenidos
    $(".nav-tema-item__titulo").hover(function () {
        $(this).closest('.nav-tema-item__icon').addClass('bg-color-base');
    }, function () {
        $(this).closest('.nav-tema-item__icon').removeClass('bg-color-base');
    });


    $('.page-topbar__menu-icon, .page-main-aside__close').on('click', function (e) {
        e.preventDefault();
        let boton = $('.btn-menu-responsive');

        let curso_main_menu = $('#page-main-aside');
        curso_main_menu.toggleClass('page-main-aside--open');

        if (curso_main_menu.hasClass('page-main-aside--open')) {
            document.getElementById("page-main-aside").style.width = "320px";
            document.getElementById("menuSecondary").style.width = "320px";
            document.getElementById("page-main").style.marginLeft = "320px";
            //document.getElementById("page-control").style.marginLeft = "320px";
            $('.page-control').hide();
            boton.addClass('active');
        } else {
            document.getElementById("page-main-aside").style.width = "0";
            document.getElementById("menuSecondary").style.width = "0";
            document.getElementById("page-main").style.marginLeft = "0";
            //document.getElementById("page-control").style.marginLeft = "0px";
            $('.page-control').show();
            boton.removeClass('active');
        }

    });


    $('[data-toggle="popover"]').popover()

    $('[data-fancybox="gallery"]').fancybox({
        // Options will go here
    });    
})

window.addEventListener('resize', function () {
    viewportWidth = window.innerWidth || document.documentElement.clientWidth;
    if (viewportWidth < 575) {
        $("#curso-topbar__nav").removeClass("show");
    } else {
        $("#curso-topbar__nav").addClass("show");
    }
}, false);