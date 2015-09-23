<?php require_once('Connection/MySql.php'); ?>
<?php require_once('all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>选课系统</title>
<link href="style.css" rel="stylesheet" type="text/css" />
<style type="text/css">
#center {
	font-family: "微软雅黑";
	font-size: 16px;
	height: auto;
	width: auto;
	margin-right: auto;
	margin-bottom: auto;
	text-align: center;
}
</style>
</head>

<script type="text/javascript">
	function fail()
	{
		alert("用户名或密码错误！");
	}
	function check(form)
	{
		var u_id = parseInt(form.username.value);
		if(form.username.value == "")
		{
			alert("用户名不能为空！");
			form.username.focus(); return false;
		}else if(form.username.value.length != 6 || u_id<100000 || u_id>999999)
		{
			alert("用户名格式错误！");
			form.username.focus(); return false;			
		}
		if(form.password.value == "")
		{
			alert("密码不能为空");
			form.password.focus(); return false;
		}
		form.submit();
	}
</script>

<?php

	$formAction = $_SERVER['PHP_SELF'];
	
	
	if((isset($_POST['MyForm'])) && $_POST['MyForm']=="form1")
	{
		if($_POST['radio'] == "stu") 
		{
			$table = "students";
			$url = "student/main.php";
			$level = 1;
		}else if($_POST['radio'] == "tea")
		{
			$table = "teachers";
			$url = "teacher/main.php";
			$level = 2;
		}else{
			$table = "managers";
			$url = "manager/main.php";
			$level = 3;
		}
		$md5_pass = md5($_POST['password']);
		$insertSQL = sprintf("select * from %s where id=%d and password=%s",$table,
						GetSQLValueString($_POST['username'],"int"),
						GetSQLValueString($md5_pass,"text"));
		$result = mysql_query($insertSQL,$MySql);
		if($result==false)
		{
			echo "<script type='text/javascript'> alert('查询失败！'); </script>";
			return;
		}
		$info = mysql_fetch_array($result);
		if(isset($info['checked']) && $info['checked'] == 0)
		{
			shell_js("alert('您的账号还未通过审核，无法登录！');");
			urlgoto($formAction);
			return;
		}
		if($info)
		{
			$_SESSION['id'] = $info['id'];
			$_SESSION['name'] = $info['name'];
			$_SESSION['level'] = $level;
			urlgoto($url);
		}else{
			echo "<script type='text/javascript'> fail(); </script> ";
		}
	}
?>

<body>
<div id="center">
  <p>选课系统</p>
  <form id="form1" name="form1" method="post" action="<?php echo $formAction; ?>">
    <p>
      <input name="radio" type="radio" id="stu" value="stu" checked="checked" />
      <label for="login">学生</label>
      <input type="radio" name="radio" id="tea" value="tea" />
      <label for="tea">教师</label>
      <input type="radio" name="radio" id="mag" value="mag" />
      <label for="mag">教务员</label>
    </p>
    <table border="0"  height="80px" align="center">
    <tr>
      <td><label for="username">用户名：</label></td>
      <td><input type="text" name="username" id="username" /></td>
    </tr>
    <tr>
      <td><label for="password">密 码：&nbsp; </label></td>
      <td><input type="password" name="password" id="password" /></td>
    </tr>
    </table>
      <input type="submit" name="login" id="login" value="登录" onclick="return check(form1)" />
      <input type="hidden" name="MyForm" value="form1" />
    </p>
    <p><a href="register.php">学生注册入口</a>
    <p><a href="reg_teacher.php">教师注册入口</a>
</form>
  <p>&nbsp;</p>
</div>
</body>
</html>
