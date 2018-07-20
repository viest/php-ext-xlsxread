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

XLSX_SHEET_T xlsx_sheet_open(XLSX_FILE_T file, const char *sheet_name, int flags)
{
    XLSX_SHEET_T sheet = xlsxioread_sheet_open(file, sheet_name, (unsigned int)flags);
    return sheet;
}

int xlsx_sheet_read_row(XLSX_SHEET_T sheet)
{
    return XLSX_READ_SHEET_ROW(sheet);
}

char *xlsx_sheet_read_column(XLSX_SHEET_T sheet)
{
    return XLSX_READ_SHEET_COLUMN(sheet);
}
