<?php
     ini_set('display_errors', 'On');
     error_reporting(E_ALL);

     $input = $_POST["input"];
     $output = array();

     $fp = fopen('input.js', 'w');
     fwrite($fp, $input);
     fclose($fp);

     shell_exec('./main.exe');
     $output["asm"] = file_get_contents('output.nasm');
     $output["terminal"] = exec("./make.sh");
     echo json_encode($output);
 ?>
