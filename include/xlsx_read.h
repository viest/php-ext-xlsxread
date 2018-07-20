#ifndef XLSX_READ_H
#define XLSX_READ_H

#include <php.h>
#include <stdlib.h>

#include "ext/standard/php_var.h"

#include "zend_types.h"
#include "zend_exceptions.h"
#include "zend.h"
#include "zend_API.h"
#include "php.h"

#include "php_xlsxread.h"
#include "library.h"
#include "file.h"
#include "sheet.h"

#define XLSX_READ_STARTUP_MODULE(module)   ZEND_MODULE_STARTUP_N(xlsxread_##module)(INIT_FUNC_ARGS_PASSTHRU)
#define XLSX_READ_STARTUP_FUNCTION(module) ZEND_MINIT_FUNCTION(xlsxread_##module)

#define XLSX_READ_NAMESPACE  "Xlsx"
#define XLSX_READ_CLASS_NAME "Read"
#define XLSX_READ_EXCEPTION_CLASS_NAME "Exception"

typedef struct _xlsx_read {
    xlsxioreader      file_ptr;
    xlsxioreadersheet sheet_ptr;
    zend_object       zo;
} xlsx_read;

static inline xlsx_read *php_xlsx_read_fetch_object(zend_object *obj) {
    return (xlsx_read *)((char *)(obj) - XtOffsetOf(xlsx_read, zo));
}

extern zend_class_entry *xlsx_read_exception_ce;
extern zend_class_entry *xlsx_read_ce;

XLSX_READ_STARTUP_FUNCTION(exception);
XLSX_READ_STARTUP_FUNCTION(read);

#define XLSX_READ_OBJECT_P(zv) php_xlsx_read_fetch_object(Z_OBJ_P(zv));

#endif

