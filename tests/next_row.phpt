--TEST--
Check for xlsxread presence
--SKIPIF--
<?php if (!extension_loaded("xlsxread")) print "skip"; ?>
--FILE--
<?php 
$fileObject = new \Xlsx\Read(__DIR__.'/./source/file.xlsx');

$row = $fileObject->openSheet('Sheet1')->nextRow();

var_dump($row);
?>
--EXPECT--
array(1) {
  [0]=>
  array(2) {
    [0]=>
    string(4) "name"
    [1]=>
    string(3) "age"
  }
}