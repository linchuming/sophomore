<?php
//all.php 为全局的php文件，记录全局变量或者函数或者必要的代码
	if (!isset($_SESSION))
	{
		session_start();
	}


	function urlgoto($url)
	{
		$str = sprintf("<script type='text/javascript'> self.location = '%s'; </script>",$url);
		echo $str;
	}
	
	function shell_js($code)
	{
		$str = sprintf("<script type='text/javascript'> %s </script>",$code);
		echo $str;
	}
	
	function Out_error()
	{
		echo "非法操作！";
		exit;
	}
	
	$days[1] = "周一"; $days[2] = "周二"; $days[3] = "周三"; $days[4] = "周四"; 
	$days[5] = "周五"; $days[6] = "周六"; $days[7] = "周日";
	
	
	function GetSQLValueString($str,$theType)
{
	$str = mysql_real_escape_string($str);
	switch($theType)
	{
		case "text":
			$str = ($str != "") ? "'" . $str . "'" : "NULL";
			break;
		case "long":
		case "int":
			$str = ($str != "") ? intval($str) : "NULL";
			break;
		case "double":
			$str = ($str != "") ? doubleval($str) : "NULL";
			break;
	}
	return $str;
}

	function DeleteCourse($c_id,$MySql)
	{
		$insertSQL = sprintf("delete from times where id=%s",GetSQLValueString($c_id,"text"));
		$result = mysql_query($insertSQL,$MySql);
		
		$insertSQL = sprintf("delete from sc where c_id=%s",GetSQLValueString($c_id,"text"));
		$result = mysql_query($insertSQL,$MySql);		
		
		$insertSQL = sprintf("delete from courses where id=%s",GetSQLValueString($c_id,"text"));
		$result = mysql_query($insertSQL,$MySql);
	}
	
	function IncCourseNumber($c_id,$MySql)
	{
		$insertSQL = sprintf("update courses set num=num+1 where id=%s",GetSQLValueString($c_id,"text"));
		mysql_query($insertSQL,$MySql);
	}
	
	function DecCourseNumber($c_id,$MySql)
	{
		$insertSQL = sprintf("update courses set num=num-1 where id=%s",GetSQLValueString($c_id,"text"));
		mysql_query($insertSQL,$MySql);
	}
	function DeleteStudent($id,$MySql)
	{
		$insertSQL = sprintf("select c_id from sc where s_id=%d",GetSQLValueString($id,"int"));
		$result = mysql_query($insertSQL,$MySql);
		while($info = mysql_fetch_array($result))
		{
			DecCourseNumber($info['c_id'],$MySql);
		}
		$insertSQL = sprintf("delete from sc where s_id=%d",GetSQLValueString($id,"int"));
		$result = mysql_query($insertSQL,$MySql);
		$insertSQL = sprintf("delete from students where id=%d",GetSQLValueString($id,"int"));		
		$result = mysql_query($insertSQL,$MySql);
	}
	
	function DeleteTeacher($id,$MySql)
	{
		$insertSQL = sprintf("select id from courses where t_id=%d",GetSQLValueString($id,"int"));
		$result = mysql_query($insertSQL,$MySql);
		while($info = mysql_fetch_array($result))
		{
			DeleteCourse($info['id'],$MySql);
		}
		$insertSQL = sprintf("delete from teachers where id=%d",GetSQLValueString($id,"int"));
		$result = mysql_query($insertSQL,$MySql);
	}
	
?>