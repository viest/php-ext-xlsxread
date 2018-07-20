--TEST--
Check for xlsxread presence
--SKIPIF--
<?php if (!extension_loaded("xlsxread")) print "skip"; ?>
--FILE--
<?php 
echo "xlsxread extension is available";
?>
--EXPECT--
xlsxread extension is available
