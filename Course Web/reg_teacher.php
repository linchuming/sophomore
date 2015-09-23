<?php require_once('Connection/MySql.php'); ?>
<?php require_once('all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>教师用户注册</title>
<link href="style.css" rel="stylesheet" type="text/css" />
<style type="text/css">
#center {
	text-align: center;
}
}
</style>
</head>
<?php
	$formAction = $_SERVER['PHP_SELF'];
	if (isset($_POST["MyForm"]) && ($_POST["MyForm"] == "form1"))
	{
		$selectSQL = "select id from teachers where id=" . GetSQLValueString($_POST['username'],"int");
		$result = mysql_query($selectSQL,$MySql);
		if($result==false)
			echo "<script type='text/javascript'> alert('查询失败！'); </script>";
		$info = mysql_fetch_array($result);
		if($info!=false)
		{
			echo "<script type='text/javascript'> alert('用户名已存在！'); self.location = 'reg_teacher.php'; </script>";
			return;
		}
		$md5_pass = md5($_POST['password']);
		$insertSQL = sprintf("insert into teachers(id,name,password,faculty,checked) values(%d,%s,%s,%s,0)",
							GetSQLValueString($_POST['username'],"int"),
							GetSQLValueString($_POST['name'],"text"),
							GetSQLValueString($md5_pass,"text"),
							GetSQLValueString($_POST['faculty'],"text"));
		$result = mysql_query($insertSQL,$MySql);
		if($result){
			$_SESSION['id'] = $_POST['username'];
			$_SESSION['name'] = $_POST['name'];
			$_SESSION['level'] = 0;
			echo "<script type='text/javascript'> self.location = 'reg_success.php'; </script>";
		}
	}
?>
<script type="text/javascript">
	function check(form)
	{
		var u_id = parseInt(form.username.value); 
		if(form.username.value == "")
		{
			alert("用户名不能为空！"); 
			form.username.focus(); return false;
		}else if(form.username.value.length != 6 || u_id<100000 || u_id>999999)
		{
			alert("用户名范围应为100000~999999！");
			form.username.focus(); return false;
		}
		
		if(form.name.value == "")
		{
			alert("姓名不能为空！");
			form.name.focus(); return false;
		}
		if(form.password.value.length<6 || form.password.value.length>16)
		{
			alert("密码长度应在6到16之间！");
			form.password.focus(); return false;
		}
		if(form.password.value != form.password2.value)
		{
			alert("两次密码输入不一致！");
			return false;
		}
		form.submit();
	}
</script>
<body>
<div id="center">
  <p>教师用户注册</p>
  <form id="form1" name="form1" method="post" action="<?php echo $formAction ?>">
    <table align="center" border="0" height="200px">
    <tr>
      <td><label for="username">用户名： </label></td>
      <td><input type="text" name="username" id="username" /></td>
    </tr>
    <tr>
      <td><label for="password">密 码：&nbsp; </label></td>
      <td><input type="password" name="password" id="password" /></td>
    </tr>
    <tr>
      <td><label for="password2">重复密码： </label></td>
      <td><input type="password" name="password2" id="password2" /></td>
    </tr>
    <tr>
      <td><label for="name">姓 名：&nbsp;</label></td>
      <td><input type="text" name="name" id="name" /></td>
    </tr>
    <tr><td>院 系：&nbsp;</td>
     <td> <select name="faculty" id="faculty">
        <option value="计算机科学与技术">计算机科学与技术</option>
        <option value="微电子科学与技术">微电子科学与技术</option>
        <option value="中文系">中文系</option>
      </select></td>
    </tr>
    </table>
    <p>
      <input type="submit" name="button" id="button" value="注册" onclick="return check(form1)" />
    </p>
	<input type="hidden" name="MyForm" value="form1" />
  </form>
  <p><a href="index.php">返回首页</a>
  <p>&nbsp;</p>
</div>
</body>
</html>
