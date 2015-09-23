<?php require_once('../Connection/MySql.php')?>
<?php require_once('../all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>教师管理界面</title>
<link href="../style.css" rel="stylesheet" type="text/css" />
<style type="text/css">
#center {
	text-align: center;
}
</style>
</head>
<?php
	if($_SESSION['level'] != 2)
	{
		Out_error();
	}
	$logoutAction = $_SERVER['PHP_SELF']."?doLogout=true";
	if(isset($_GET['doLogout']) && $_GET['doLogout']=="true")
	{
		$_SESSION['id'] = NULL;
		$_SESSION['name'] = NULL;
		$_SESSION['level'] = NULL;
		unset($_SESSION['id']);
		unset($_SESSION['name']);
		unset($_SESSION['level']);
		
		//shell_js("window.opener=null;window.open('','_self');window.close();");
		urlgoto("../index.php");
		return;
	}
	if(!isset($_GET['open'])) $open = 1;
	$Myiframe = "<iframe id='myframe' src='course.php' frameBorder=0 width='100%' height='600'>";
	if($_GET['open'] == "1")
	{
		$Myiframe = "<iframe id='myframe' src='course.php' frameBorder=0 width='100%' height='600'>";
		$open = 1;
	}else if($_GET['open'] == "2")
	{
		$Myiframe = "<iframe id='myframe' src='add_course.php' frameBorder=0 width='100%' height='600'>";
		$open = 2;
	}else if($_GET['open'] == "3")
	{
		$Myiframe = "<iframe id='myframe' src='../query_courses.php' frameBorder=0 width='100%' height='600'>";
		$open = 3;
	}else if($_GET['open'] == "4")
	{
		$Myiframe = "<iframe id='myframe' src='../modify_password.php' frameBorder=0 width='100%' height='600'>";
		$open = 4;
	}
?>
<body>
<div id="center">
  <p>教师管理界面</p>
  <p align="left">您好！老师: <?php echo $_SESSION['name'];?></p>
  <table align="center" width="500" border="0">
    <tr>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=1"; ?>" <?php if($open==1) echo "style='text-decoration:underline'"; ?>>我的课程</td>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=2"; ?>" <?php if($open==2) echo "style='text-decoration:underline'"; ?>>添加课程</td>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=3"; ?>" <?php if($open==3) echo "style='text-decoration:underline'"; ?>>课程查询</td>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=4"; ?>" <?php if($open==4) echo "style='text-decoration:underline'"; ?>>修改密码</td>
      <td><a href="<?php echo $logoutAction; ?>">注销</td>
    </tr>
  </table>
</div>
<p> </p>
<?php
	echo $Myiframe;
?>
</body>
</html>
