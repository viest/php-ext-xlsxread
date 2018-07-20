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
#include "library.h"

XLSX_FILE_T xlsx_file_open(const char *path) {
    XLSX_FILE_T file;

    if ((file = xlsxioread_open(path)) == NULL) {
        zend_throw_exception(xlsx_read_exception_ce, "Failed to open file", 100);
        return NULL;
    }

    return file;
}