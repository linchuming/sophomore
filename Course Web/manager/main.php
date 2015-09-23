<?php require_once('../Connection/MySql.php')?>
<?php require_once('../all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>教务员管理界面</title>
<link href="../style.css" rel="stylesheet" type="text/css" />
<style type="text/css">
#center {
	text-align: center;
}
</style>
</head>
<?php
	if($_SESSION['level'] != 3)
    {
    	Out_error();
    }
	
	$logoutAction = $_SERVER['PHP_SELF']."?doLogout=true";
	$Myiframe = "";
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
	if(isset($_GET['open']) && $_GET['open'] == "1")
	{
		/*
		shell_js("
			document.getElementById('ifrmid').style.display = 'block';
			document.getElementById('ifrmid').src = 'check_stu.php';");		*/
		$Myiframe = "<iframe id='myframe' src='check_stu.php' frameBorder=0 width='100%' height='600'>";
		$open = 1;
			
	}else if($_GET['open'] == "2")
	{
		$Myiframe = "<iframe id='myframe' src='check_tea.php' frameBorder=0 width='100%' height='600'>";
		$open = 2;
	}else if($_GET['open'] == "3")
	{
		$Myiframe = "<iframe id='myframe' src='info_stu.php' frameBorder=0 width='100%' height='600'>";
		$open = 3;
	}else if($_GET['open'] == "4")
	{
		$Myiframe = "<iframe id='myframe' src='info_tea.php' frameBorder=0 width='100%' height='600'>";
		$open = 4;
	}else if($_GET['open'] == "5")
	{
		$Myiframe = "<iframe id='myframe' src='../query_courses.php' frameBorder=0 width='100%' height='600'>";	
        $open = 5;		
	}else if($_GET['open'] == "6")
	{
		$Myiframe = "<iframe id='myframe' src='../modify_password.php' frameBorder=0 width='100%' height='600'>";
		$open = 6;
	}
?>
<body>
<p align="center">教务员管理界面</p>
<p>您好！教务员：<?php echo $_SESSION['name']; ?></p>
<div id="center">
  <table align="center" width="700" border="0">
    <tr>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=1"; ?>" <?php if($open==1) echo "style='text-decoration:underline'"; ?>>审核学生用户</a></td>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=2"; ?>" <?php if($open==2) echo "style='text-decoration:underline'"; ?>>审核教师用户</td>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=3"; ?>" <?php if($open==3) echo "style='text-decoration:underline'"; ?>>查看学生信息</td>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=4"; ?>" <?php if($open==4) echo "style='text-decoration:underline'"; ?>>查看教师信息</td>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=5"; ?>" <?php if($open==5) echo "style='text-decoration:underline'"; ?>>课程查询</td>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=6"; ?>" <?php if($open==6) echo "style='text-decoration:underline'"; ?>>修改密码</td>
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
