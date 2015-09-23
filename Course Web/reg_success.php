<?php require_once('Connection/MySql.php'); ?>
<?php require_once('all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>注册成功</title>
<link href="style.css" rel="stylesheet" type="text/css" />
<style type="text/css">
#center {
	text-align: center;
}
</style>
</head>
<?php
	if($_SESSION['level'] != 0)
	{
		echo "非法操作";
		return;
	}
?>
<body>
<div id="center">
  <p>恭喜您！注册成功！</p>
  <p>您的用户名为：<?php echo $_SESSION['id']?></p>
  <p>您的姓名为：<?php echo $_SESSION['name']?></p>
  <p>您的账号将由管理员进行审核，审核成功才可登录系统！</p>
  <p><a href="index.php">返回首页</a>
</div>
</body>
</html>
