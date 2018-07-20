--TEST--
Check for xlsxread presence
--SKIPIF--
<?php if (!extension_loaded("xlsxread")) print "skip"; ?>
--FILE--
<?php 
$fileObject = new \Xlsx\Read(__DIR__.'/./source/file.xlsx');

$data = $fileObject->openSheet('Sheet1')->data();

var_dump($data);
?>
--EXPECT--
array(2) {
  [0]=>
  array(2) {
    [0]=>
    string(4) "name"
    [1]=>
    string(3) "age"
  }
  [1]=>
  array(3) {
    [0]=>
    string(0) ""
    [1]=>
    string(0) ""
    [2]=>
    string(2) "21"
  }
}

