PHP_ARG_WITH(xlsxread, for xlsxread support,
[  --with-xlsxread             Include xlsxread support])

PHP_ARG_WITH(libexpat, system libexpat,
[  --with-libexpat=DIR Use system library], no, no)

if test "$PHP_XLSXREAD" != "no"; then
    xlsxread_sources="xlsxread.c \
    src/file.c \
    src/sheet.c \
    src/read.c \
    src/exception.c \
    lib/xlsxio/xlsxio_read.c \
    lib/xlsxio/xlsxio_read_sharedstrings.c
    "

    AC_MSG_CHECKING([Check libexpat support])

    for i in $PHP_LIBEXPAT /usr/local /usr; do
        if test -r $i/include/expat.h; then
            AC_MSG_CHECKING([Check libexpat library])
            EXPAT_DIR=$i
            PHP_ADD_INCLUDE($i/include)
            PHP_CHECK_LIBRARY(expat, XML_ParserCreate,
            [
                PHP_ADD_LIBRARY_WITH_PATH(expat, $i/$PHP_LIBDIR, XLSXREAD_SHARED_LIBADD)
            ],[
                AC_MSG_ERROR([Wrong libexpat version or library not found])
            ],[
                -L$i/$PHP_LIBDIR -lm
            ])

            break
        else
            AC_MSG_RESULT([no, found in $i])
        fi
    done

    AC_MSG_CHECKING([Check libzip support])

    for i in /usr/local /usr; do
        if test -r $i/include/zip.h; then
            AC_MSG_CHECKING([Check libzip library])
            LIBZIP_DIR=$i
            PHP_ADD_INCLUDE($i/include)
            PHP_CHECK_LIBRARY(zip, zip_libzip_version,
            [
                PHP_ADD_LIBRARY_WITH_PATH(zip, $i/$PHP_LIBDIR, XLSXREAD_SHARED_LIBADD)
            ],[
                AC_MSG_ERROR([Wrong libzip version or library not found])
            ],[
                -L$i/$PHP_LIBDIR -lm
            ])

            break
        else
            AC_MSG_RESULT([no, found in $i])
        fi
    done

    if test -z "$EXPAT_DIR"; then
        AC_MSG_ERROR([libexpat library not found])
    fi

    if test -z "$LIBZIP_DIR"; then
        AC_MSG_ERROR([libzip library not found])
    fi

    PHP_ADD_INCLUDE($XLSXREAD_DIR/include)

    PHP_SUBST(XLSXREAD_SHARED_LIBADD)

    PHP_NEW_EXTENSION(xlsxread, $xlsxread_sources, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)

    PHP_ADD_BUILD_DIR([$ext_builddir/lib/xlsxio])
    PHP_ADD_BUILD_DIR([$ext_builddir/src])
fi
