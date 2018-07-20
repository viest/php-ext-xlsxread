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


#ifndef XLSX_READ_SHEET_H
#define XLSX_READ_SHEET_H

#include "library.h"

XLSX_SHEET_T xlsx_sheet_open(XLSX_FILE_T file, const char *sheet_name, int flags);
char *xlsx_sheet_read_column(XLSX_SHEET_T sheet);
int xlsx_sheet_read_row(XLSX_SHEET_T sheet);

#endif
