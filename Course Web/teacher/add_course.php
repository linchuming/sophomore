<?php require_once('../Connection/MySql.php')?>
<?php require_once('../all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>添加课程</title>
<link href="../style.css" rel="stylesheet" type="text/css" />
<style type="text/css">
#center {
	text-align: center;
}
</style>
</head>
<script type="text/javascript">
function check(form)
{
	if(form.id.value == "")
	{
		alert("课程号不能为空！");
		form.id.focus(); return false;
	}
	if(form.id.value.length > 16)
	{
		alert("课程号长度不能超过16！");
		form.id.focus(); return false;
	}
	if(form.room.value == "")
	{
		alert("教室不能为空！");
		form.room.focus(); return false;
	}
	if(form.maxnum.value == "")
	{
		alert("总人数不能为空！");
		form.maxnum.focus(); return false;
	}
	form.submit();
}
</script>
<?php
	if($_SESSION['level'] != 2) Out_error();
	if($_POST['MyForm'] == "form1")
	{
		$insertSQL = sprintf("select id from courses where id=%s",GetSQLValueString($_POST['id'],"text"));
		$result = mysql_query($insertSQL,$MySql);
		$info = mysql_fetch_array($result);
		if($info != false)
		{
			shell_js("alert('课程号已存在！请检查！');");
			urlgoto($_SERVER['PHP_SELF']); return;
		}
		$insertSQL = sprintf("insert into courses(id,name,room,maxnum,num,t_id) values(%s,%s,%s,%d,%d,%d)",
							GetSQLValueString($_POST['id'],"text"),
							GetSQLValueString($_POST['name'],"text"),
							GetSQLValueString($_POST['room'],"text"),
							GetSQLValueString($_POST['maxnum'],"int"),
							0,GetSQLValueString($_SESSION['id'],"int"));
		$result = mysql_query($insertSQL,$MySql);
		if($result)
		{
			shell_js("alert('添加课程成功！');");
			urlgoto($_SERVER['PHP_SELF']); return;
		}
		
	}
?>
<body>
<div id="center">
  <form id="form1" name="form1" method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
  	<table align="center" border="0" height="150px">
    <tr>
      <td><label for="id">课程号：</label></td>
      <td><input type="text" name="id" id="id" /></td>
    </tr>
    <tr>
      <td><label for="name">课程名：</label></td>
      <td><input type="text" name="name" id="name" /></td>
    </tr>
    <tr>
      <td><label for="room">教 室：</label></td>
      <td><input type="text" name="room" id="room" /></td>
    </tr>
    <tr>
      <td><label for="maxnum">总人数：</label></td>
      <td><input type="text" name="maxnum" id="maxnum" /></td>
    </tr>
    </table>
    <p>
      <input type="submit" name="button" id="button" value="添加" onclick="return check(form1)" />
      <input type="hidden" name="MyForm" value="form1" />
    </p>
  </form>
</div>
</body>
</html>
