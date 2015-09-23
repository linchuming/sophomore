<?php
$MySql = mysql_connect(SAE_MYSQL_HOST_M.':'.SAE_MYSQL_PORT,SAE_MYSQL_USER,SAE_MYSQL_PASS) or trigger_error(mysql_error(),E_USER_ERROR); 
mysql_select_db(SAE_MYSQL_DB,$MySql);


?>
