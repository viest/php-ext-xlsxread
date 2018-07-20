### XlsxRead PHP Extension

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