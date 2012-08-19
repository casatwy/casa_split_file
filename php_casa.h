/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id: header 321634 2012-01-01 13:15:04Z felipe $ */

#ifndef PHP_CASA_H
#define PHP_CASA_H

extern zend_module_entry casa_module_entry;
#define phpext_casa_ptr &casa_module_entry

#ifdef PHP_WIN32
#	define PHP_CASA_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_CASA_API __attribute__ ((visibility("default")))
#else
#	define PHP_CASA_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(casa);
PHP_MSHUTDOWN_FUNCTION(casa);
PHP_RINIT_FUNCTION(casa);
PHP_RSHUTDOWN_FUNCTION(casa);
PHP_MINFO_FUNCTION(casa);

PHP_FUNCTION(confirm_casa_compiled);	/* For testing, remove later. */
PHP_FUNCTION(casa_split_file);

/* 
  	Declare any global variables you may need between the BEGIN
	and END macros here:     

ZEND_BEGIN_MODULE_GLOBALS(casa)
	long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(casa)
*/

/* In every utility function you add that needs to use variables 
   in php_casa_globals, call TSRMLS_FETCH(); after declaring other 
   variables used by that function, or better yet, pass in TSRMLS_CC
   after the last function argument and declare your utility function
   with TSRMLS_DC after the last declared argument.  Always refer to
   the globals in your function as CASA_G(variable).  You are 
   encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/

#ifdef ZTS
#define CASA_G(v) TSRMG(casa_globals_id, zend_casa_globals *, v)
#else
#define CASA_G(v) (casa_globals.v)
#endif

#endif	/* PHP_CASA_H */

/*used for mmap*/
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
