--TEST--
Check for xlsxread presence
--SKIPIF--
<?php if (!extension_loaded("xlsxread")) print "skip"; ?>
--FILE--
<?php 
$fileObject = new \Xlsx\Read(__DIR__.'/./source/file.xlsx');

$sheet_one = $fileObject->openSheet('Sheet1')->data();
$sheet_two = $fileObject->openSheet('Sheet2')->data();

var_dump($sheet_one, $sheet_two);
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
array(2) {
  [0]=>
  array(2) {
    [0]=>
    string(4) "name"
    [1]=>
    string(3) "age"
  }
  [1]=>
  array(2) {
    [0]=>
    string(3) "wjx"
    [1]=>
    string(2) "22"
  }
}