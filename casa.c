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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_casa.h"

/* If you declare any globals in php_casa.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(casa)
*/

/* True global resources - no need for thread safety here */
static int le_casa;

/* {{{ casa_functions[]
 *
 * Every user visible function must have an entry in casa_functions[].
 */
const zend_function_entry casa_functions[] = {
	PHP_FE(confirm_casa_compiled,	NULL)		/* For testing, remove later. */
	PHP_FE(casa_split_file,	NULL)
	PHP_FE_END	/* Must be the last line in casa_functions[] */
};
/* }}} */

/* {{{ casa_module_entry
 */
zend_module_entry casa_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"casa",
	casa_functions,
	PHP_MINIT(casa),
	PHP_MSHUTDOWN(casa),
	PHP_RINIT(casa),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(casa),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(casa),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_CASA
ZEND_GET_MODULE(casa)
#endif

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("casa.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_casa_globals, casa_globals)
    STD_PHP_INI_ENTRY("casa.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_casa_globals, casa_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_casa_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_casa_init_globals(zend_casa_globals *casa_globals)
{
	casa_globals->global_value = 0;
	casa_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(casa)
{
	/* If you have INI entries, uncomment these lines 
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(casa)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(casa)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(casa)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(casa)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "casa support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */


/* Remove the following function when you have succesfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_casa_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_casa_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "casa", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and 
   unfold functions in source code. See the corresponding marks just before 
   function definition, where the functions purpose is also documented. Please 
   follow this convention for the convenience of others editing your code.
*/

/* {{{ proto array casa_split_file(string dir, string filename)
    */
PHP_FUNCTION(casa_split_file)
{
	char *dir = NULL;
	char *filename = NULL;
	int argc = ZEND_NUM_ARGS();
	int dir_len;
	int filename_len;

	if (zend_parse_parameters(argc TSRMLS_CC, "ss", &dir, &dir_len, &filename, &filename_len) == FAILURE) 
		return;

	php_error(E_WARNING, "casa_split_file: not yet implemented");
}
/* }}} */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
