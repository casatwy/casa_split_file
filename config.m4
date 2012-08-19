dnl $Id$
dnl config.m4 for extension casa

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(casa, for casa support,
dnl Make sure that the comment is aligned:
dnl [  --with-casa             Include casa support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(casa, whether to enable casa support,
dnl Make sure that the comment is aligned:
[  --enable-casa           Enable casa support])

if test "$PHP_CASA" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-casa -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/casa.h"  # you most likely want to change this
  dnl if test -r $PHP_CASA/$SEARCH_FOR; then # path given as parameter
  dnl   CASA_DIR=$PHP_CASA
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for casa files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       CASA_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$CASA_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the casa distribution])
  dnl fi

  dnl # --with-casa -> add include path
  dnl PHP_ADD_INCLUDE($CASA_DIR/include)

  dnl # --with-casa -> check for lib and symbol presence
  dnl LIBNAME=casa # you may want to change this
  dnl LIBSYMBOL=casa # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $CASA_DIR/lib, CASA_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_CASALIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong casa lib version or lib not found])
  dnl ],[
  dnl   -L$CASA_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(CASA_SHARED_LIBADD)

  PHP_NEW_EXTENSION(casa, casa.c, $ext_shared)
fi
