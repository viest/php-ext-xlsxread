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

#include "xlsx_read.h"

zend_class_entry *xlsx_read_ce;

static zend_object_handlers xlsx_read_object_handlers;

static zend_always_inline void *xlsx_read_object_alloc(size_t obj_size, zend_class_entry *ce) {
    void *obj = emalloc(obj_size);
    memset(obj, 0, obj_size);
    return obj;
}

/* {{{ xlsx_read_objects_new
 */
PHP_XLSXREAD_API zend_object *xlsx_read_objects_new(zend_class_entry *ce)
{
    xlsx_read *intern = xlsx_read_object_alloc(sizeof(xlsx_read), ce);

    zend_object_std_init(&intern->zo, ce);
    object_properties_init(&intern->zo, ce);

    intern->zo.handlers = &xlsx_read_object_handlers;

    return &intern->zo;
}
/* }}} */

/* {{{ xlsx_read_objects_free
 */
static void xlsx_read_objects_free(zend_object *object)
{
    xlsx_read *intern = php_xlsx_read_fetch_object(object);

    xlsxioread_sheet_close(intern->sheet_ptr);
    xlsxioread_close(intern->file_ptr);

    zend_object_std_dtor(&intern->zo);
}
/* }}} */

/** {{{ \Xlsx\Read::__construct()
 */
PHP_METHOD (xlsx_read, __construct) {
    zend_string *file_path = NULL;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STR(file_path)
    ZEND_PARSE_PARAMETERS_END();

    xlsx_read *object = XLSX_READ_OBJECT_P(getThis());
    object->file_ptr  = xlsx_file_open(ZSTR_VAL(file_path));
}
/* }}} */

/** {{{ \Xlsx\Read::openSheet()
 */
PHP_METHOD (xlsx_read, openSheet) {
    zend_string *sheet_name = NULL;

    ZEND_PARSE_PARAMETERS_START(0, 1)
            Z_PARAM_OPTIONAL
            Z_PARAM_STR(sheet_name)
    ZEND_PARSE_PARAMETERS_END();

    ZVAL_COPY(return_value, getThis());

    xlsx_read *object = XLSX_READ_OBJECT_P(return_value);

    if (!object->file_ptr) {
        RETURN_FALSE;
    }

    if (sheet_name) {
        object->sheet_ptr = xlsx_sheet_open(object->file_ptr, ZSTR_VAL(sheet_name), XLSXIOREAD_SKIP_EMPTY_ROWS);
    } else {
        object->sheet_ptr = xlsx_sheet_open(object->file_ptr, NULL, XLSXIOREAD_SKIP_EMPTY_ROWS);
    }
}
/* }}} */

/** {{{ \Xlsx\Read::data()
 */
PHP_METHOD (xlsx_read, data) {
    xlsx_read *object;
    char *_value;

    array_init(return_value);

    object = XLSX_READ_OBJECT_P(getThis());

    if (!object->file_ptr) {
        RETURN_FALSE;
    }

    while (xlsx_sheet_read_row(object->sheet_ptr))
    {
        zval _tmp_row;
        array_init(&_tmp_row);

        while ((_value = xlsx_sheet_read_column(object->sheet_ptr)) != NULL)
        {
            add_next_index_stringl(&_tmp_row, _value, strlen(_value));
        }

        add_next_index_zval(return_value, &_tmp_row);
    }
}
/* }}} */

/** {{{ \Xlsx\Read::nextRow()
 */
PHP_METHOD (xlsx_read, nextRow)
{
    xlsx_read *object;
    char *_value;
    zval _tmp_row;

    array_init(return_value);
    array_init(&_tmp_row);

    object = XLSX_READ_OBJECT_P(getThis());

    if (!object->file_ptr) {
        RETURN_FALSE;
    }

    xlsx_sheet_read_row(object->sheet_ptr);

    while ((_value = xlsx_sheet_read_column(object->sheet_ptr)) != NULL)
    {
        add_next_index_stringl(&_tmp_row, _value, strlen(_value));
    }

    add_next_index_zval(return_value, &_tmp_row);
}
/* }}} */

/** {{{ xls_methods
*/
zend_function_entry xlsx_read_methods[] = {
        PHP_ME(xlsx_read, __construct, NULL, ZEND_ACC_PUBLIC)
        PHP_ME(xlsx_read, openSheet,   NULL, ZEND_ACC_PUBLIC)
        PHP_ME(xlsx_read, data,        NULL, ZEND_ACC_PUBLIC)
        PHP_ME(xlsx_read, nextRow,     NULL, ZEND_ACC_PUBLIC)
        PHP_FE_END
};
/* }}} */

/** {{{ XLSX_READ_STARTUP_FUNCTION
*/
XLSX_READ_STARTUP_FUNCTION(read) {
    zend_class_entry ce;

    INIT_NS_CLASS_ENTRY(ce, XLSX_READ_NAMESPACE, XLSX_READ_CLASS_NAME, xlsx_read_methods);

    ce.create_object = xlsx_read_objects_new;
    xlsx_read_ce     = zend_register_internal_class(&ce);

    memcpy(&xlsx_read_object_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
    xlsx_read_object_handlers.offset   = XtOffsetOf(xlsx_read, zo);
    xlsx_read_object_handlers.free_obj = xlsx_read_objects_free;

    return SUCCESS;
}
/* }}} */