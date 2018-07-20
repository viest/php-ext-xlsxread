/*
  +----------------------------------------------------------------------+
  | XlsxRead Extension                                                    |
  +----------------------------------------------------------------------+
  | Copyright (c) 2018-2018 The Viest                                    |
  +----------------------------------------------------------------------+
  | http://www.viest.me                                                  |
  +----------------------------------------------------------------------+
  | Author: viest <wjx@php.net>                                          |
  +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_xlsxread.h"

#include "xlsx_read.h"

/* If you declare any globals in php_xlsxread.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(xlsxread)
*/

static int le_xlsxread;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("xlsxread.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_xlsxread_globals, xlsxread_globals)
    STD_PHP_INI_ENTRY("xlsxread.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_xlsxread_globals, xlsxread_globals)
PHP_INI_END()
*/
/* }}} */

/* {{{ php_xlsxread_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_xlsxread_init_globals(zend_xlsxread_globals *xlsxread_globals)
{
	xlsxread_globals->global_value = 0;
	xlsxread_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ xlsx_read_version
 */
PHP_FUNCTION(xlsx_read_version) {
    RETURN_STRING(PHP_XLSXREAD_VERSION);
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(xlsxread)
{
	XLSX_READ_STARTUP_MODULE(read);

	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(xlsxread)
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
PHP_RINIT_FUNCTION(xlsxread)
{
#if defined(COMPILE_DL_XLSXREAD) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(xlsxread)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(xlsxread)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "xlsxread support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ xlsxread_functions[]
 */
const zend_function_entry xlsxread_functions[] = {
		PHP_FE(xlsx_read_version,	NULL)
		PHP_FE_END
};
/* }}} */

/* {{{ xlsxread_module_entry
 */
zend_module_entry xlsxread_module_entry = {
	STANDARD_MODULE_HEADER,
	"xlsxread",
	xlsxread_functions,
	PHP_MINIT(xlsxread),
	PHP_MSHUTDOWN(xlsxread),
	PHP_RINIT(xlsxread),
	PHP_RSHUTDOWN(xlsxread),
	PHP_MINFO(xlsxread),
	PHP_XLSXREAD_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_XLSXREAD
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(xlsxread)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
