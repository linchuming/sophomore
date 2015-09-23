<?php require_once('Connection/MySql.php'); ?>
<?php require_once('all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>密码修改</title>
<link href="style.css" rel="stylesheet" type="text/css" />
<style type="text/css">
#center {
	text-align: center;
}
</style>
</head>
<?php
	if(isset($_SESSION['level']) && $_SESSION['level'] == 0) Out_error();
	if($_SESSION['level'] == 1) $table = "students";
	else if($_SESSION['level'] == 2) $table = "teachers";
	else if($_SESSION['level'] == 3) $table = "managers";
	if($_POST['MyForm'] == "form1")
	{
		$md5pass = md5($_POST['n_pd']);
		$insertSQL = sprintf("update %s set password=%s where id=%d",$table,
							GetSQLValueString($md5pass,"text"),
							GetSQLValueString($_SESSION['id'],"int"));
		$result = mysql_query($insertSQL,$MySql);
		if($result) shell_js("alert('密码修改成功！');");
	}
?>
<script type="text/javascript">
function check(form)
{
	if(form.password.value == "")
	{
		alert("当前密码不能为空！");
		form.password.focus(); return false;
	}
	if(form.n_pd.value == "")
	{
		alert("新密码不能为空！");
		form.n_pd.focus(); return false;
	}
	if(form.c_pd.value == "")
	{
		alert("重复密码不能为空！");
		form.c_pd.focus(); return false;
	}
	if(form.n_pd.value.length<6 || form.n_pd.value.length>16)
	{
		alert("新密码长度应为6到16之间！");
		form.n_pd.focus(); return false;
	}
	if(form.n_pd.value != form.c_pd.value)
	{
		alert("新密码与重复密码不一致！"); return false;
	}
	form.submit();
}
</script>
<body>
<div id="center">
  <form id="form1" name="form1" method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
    <table align="center" border="0" height="150px">
    <tr>
      <td><label for="password">当前密码：</label></td>
      <td><input type="password" name="password" id="password" /></td>
    </tr>
    <tr>
      <td><label for="n_pd">新密码：</label></td>
      <td><input type="password" name="n_pd" id="n_pd" /></td>
    </tr>
    <tr>
      <td><label for="c_pd">重复密码：</label></td>
      <td><input type="password" name="c_pd" id="c_pd" /></td>
    </tr>
    </table>
    <p>
      <input type="submit" name="button" id="button" value="提交" onclick="return check(form1)" />
      <input type="hidden" name="MyForm" value="form1" />
    </p>
  </form>
</div>
</body>
</html>
