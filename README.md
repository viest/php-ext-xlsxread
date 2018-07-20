### XlsxRead PHP Extension

[![Build Status](https://travis-ci.org/viest/php-ext-xlsxread.svg?branch=master)](https://travis-ci.org/viest/php-ext-xlsxread)

#### Install

```bash
git clone git@github.com:viest/php-ext-xlsxread.git

phpize && ./configure --with-php-config=path/php-config && make && make install
```

#### Depend

* expat
* libzip

#### Document

```php
$fileObject = new \Xlsx\Read('path/file.xlsx');

$allData = $fileObject->openSheet('Sheet1')
    ->data();

$rowData = $fileObject->openSheet('Sheet1')
    ->nextRow()
```