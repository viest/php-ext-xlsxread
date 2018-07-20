#ifndef XLSX_READ_LIBRARY_H
#define XLSX_READ_LIBRARY_H

#include "xlsxio/xlsxio_read.h"

#define XLSX_FILE_T  xlsxioreader
#define XLSX_SHEET_T xlsxioreadersheet

#define XLSX_READ_SHEET_ROW(sheet)    xlsxioread_sheet_next_row(sheet)
#define XLSX_READ_SHEET_COLUMN(sheet) xlsxioread_sheet_next_cell(sheet)

#endif
