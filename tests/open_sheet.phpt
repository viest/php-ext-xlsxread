--TEST--
Check for xlsxread presence
--SKIPIF--
<?php if (!extension_loaded("xlsxread")) print "skip"; ?>
--FILE--
<?php 
$fileObject = new \Xlsx\Read(__DIR__.'/./source/file.xlsx');

$sheet = $fileObject->openSheet('Sheet1');

var_dump($sheet);
?>
--EXPECT--
object(Xlsx\Read)#1 (0) {
}

