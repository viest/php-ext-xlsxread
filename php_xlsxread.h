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

#ifndef PHP_XLSXREAD_H
#define PHP_XLSXREAD_H

extern zend_module_entry xlsxread_module_entry;
#define phpext_xlsxread_ptr &xlsxread_module_entry

#define PHP_XLSXREAD_VERSION "0.1.0"

#ifdef PHP_WIN32
#	define PHP_XLSXREAD_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_XLSXREAD_API __attribute__ ((visibility("default")))
#else
#	define PHP_XLSXREAD_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

/*
  	Declare any global variables you may need between the BEGIN
	and END macros here:
ZEND_BEGIN_MODULE_GLOBALS(xlsxread)
	zend_long  global_value;
	char *global_string;
ZEND_END_MODULE_GLOBALS(xlsxread)
*/

/* Always refer to the globals in your function as XLSXREAD_G(variable).
   You are encouraged to rename these macros something shorter, see
   examples in any other php module directory.
*/
#define XLSXREAD_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(xlsxread, v)

#if defined(ZTS) && defined(COMPILE_DL_XLSXREAD)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

PHP_MINIT_FUNCTION(xlsxread);
PHP_MSHUTDOWN_FUNCTION(xlsxread);
PHP_RINIT_FUNCTION(xlsxread);
PHP_RSHUTDOWN_FUNCTION(xlsxread);
PHP_MINFO_FUNCTION(xlsxread);

#endif


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
