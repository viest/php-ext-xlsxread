/*
  +----------------------------------------------------------------------+
  | XlsWriter Extension                                                  |
  +----------------------------------------------------------------------+
  | Copyright (c) 2017-2018 The Viest                                    |
  +----------------------------------------------------------------------+
  | http://www.viest.me                                                  |
  +----------------------------------------------------------------------+
  | Author: viest <dev@service.viest.me>                                 |
  +----------------------------------------------------------------------+
*/

#include "xlsx_read.h"

zend_class_entry *xlsx_read_exception_ce;

/** {{{ exception_methods
*/
zend_function_entry exception_methods[] = {
        PHP_FE_END
};
/* }}} */

/** {{{ XLSX_READ_STARTUP_FUNCTION
*/
XLSX_READ_STARTUP_FUNCTION(exception) {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, XLSX_READ_NAMESPACE, XLSX_READ_EXCEPTION_CLASS_NAME, exception_methods);

    xlsx_read_exception_ce = zend_register_internal_class_ex(&ce, zend_ce_exception);

    return SUCCESS;
}
/* }}} */
