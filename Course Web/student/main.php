<?php require_once('../Connection/MySql.php')?>
<?php require_once('../all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>学生界面</title>
<link href="../style.css" rel="stylesheet" type="text/css" />
<style type="text/css">
#center {
	text-align: center;
}
#sc {
	width: 30%;
	float: left;
}
#right {
	width: 70%;
	float: right;
}
</style>
</head>
<?php
	if($_SESSION['level'] == 1)
	{
		$Myiframe = "<iframe id='myframe' src='schedule.php' frameBorder=0 width='100%' height='600'>";
		if(!isset($_GET['open'])) $open = 1;
		if($_GET['open'] == "1")
		{
			$Myiframe = "<iframe id='myframe' src='schedule.php' frameBorder=0 width='100%' height='600'>";
			$open = 1;
		}else if($_GET['open'] == "2")
		{
			$Myiframe = "<iframe id='myframe' src='../query_courses.php' frameBorder=0 width='100%' height='600'>";
			$open = 2;
		}else if($_GET['open'] == "3")
		{
			$Myiframe = "<iframe id='myframe' src='../modify_password.php' frameBorder=0 width='100%' height='600'>";
			$open = 3;
		}
		
		
		if(isset($_GET['doLogout']) && $_GET['doLogout']=="true")
		{
			$_SESSION['id'] = NULL;
			$_SESSION['name'] = NULL;
			$_SESSION['level'] = NULL;
			unset($_SESSION['id']);
			unset($_SESSION['name']);
			unset($_SESSION['level']);
		
			urlgoto("../index.php");
			return;
		}
		
		if($_POST['MyForm'] == "select")
		{
			$insertSQL = sprintf("select * from courses where id=%s",GetSQLValueString($_POST['c_id'],"text"));
			$result = mysql_query($insertSQL,$MySql);
			$info = mysql_fetch_array($result);
			if($info != false)
			{
				$flag = true;
				if($info['num'] >= $info['maxnum'])
				{
					shell_js("alert('该课选课人数已达到上限！');");
					goto fail;
				}
				$insertSQL = sprintf("select * from times where id=%s",GetSQLValueString($_POST['c_id'],"text"));
				$result = mysql_query($insertSQL,$MySql);
				while($info = mysql_fetch_array($result))
				{
					if($flag == false) break;
					$insertSQL = sprintf("select times.days,times.begin,times.end from times,sc where times.id = sc.c_id
											and sc.s_id = %d",GetSQLValueString($_SESSION['id'],"int"));
					$p_result = mysql_query($insertSQL,$MySql);
					while($time = mysql_fetch_array($p_result))
					{
						if($info['days'] == $time['days'])
						{
							if(!($info['end']>$time['begin']&&$info['end']>$time['end'] || $time['end']>$info['begin']&&$time['end']>$info['end'] ))
							{
								$flag = false;
								break;
							}
						}
					}
					if($flag == false) break;
				}
				if($flag)
				{
					$insertSQL = sprintf("insert into sc(s_id,c_id) values(%d,%s)",
										GetSQLValueString($_SESSION['id'],"int"),
										GetSQLValueString($_POST['c_id'],"text"));
					$result = mysql_query($insertSQL,$MySql);
					if($result)
					{
						$insertSQL = sprintf("update courses set num=num+1 where id=%s",GetSQLValueString($_POST['c_id'],"text"));
						mysql_query($insertSQL);
						shell_js("alert('选课成功！');");
					}
				}else shell_js("alert('该课程与其他课程有冲突，请检查！');");
			}else{
				shell_js("alert('该课程不存在！');");
			}
		}
		
		if($_POST['MyForm'] == "cancel")
		{
			$insertSQL = sprintf("select * from sc where s_id=%d and c_id=%s",
								GetSQLValueString($_SESSION['id'],"int"),
								GetSQLValueString($_POST['c_id'],"text"));
			$result = mysql_query($insertSQL,$MySql);
			$info = mysql_fetch_array($result);
			if($info == false) 
			{
				shell_js("alert('请检查课程号是否正确！');");
				goto fail;
			}
			$insertSQL = sprintf("delete from sc where s_id=%d and c_id=%s",
								GetSQLValueString($_SESSION['id'],"int"),
								GetSQLValueString($_POST['c_id'],"text"));
			$result = mysql_query($insertSQL,$MySql);
			if($result)
			{
				$insertSQL = sprintf("update courses set num=num-1 where id=%s",GetSQLValueString($_POST['c_id'],"text"));
				mysql_query($insertSQL);
				shell_js("alert('退课成功！');");
			}else{
				shell_js("alert('退课失败，请检查课程号是否正确！');");
			}
		}
		
		fail:
	}else Out_error();
?>

<script type="text/javascript">
	function Select(form)
	{
		if(form.c_id.value == "")
		{
			alert("请输入课程号！");  form.c_id.focus(); return false;
		}
		form.MyForm.value = "select";
		form.submit();
	}
	
	function Cancel(form)
	{
		if(form.c_id.value == "")
		{
			alert("请输入课程号！");  form.c_id.focus(); return false;
		}
		form.MyForm.value = "cancel";
		form.submit();
	}
</script>
<body>
<div id="center">
  <p>学生选课界面</p>
  <p align="left">您好！同学：<?php echo $_SESSION['name'];?></p>
  <table align="center" width="500" border="0">
    <tr>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=1"; ?>" <?php if($open==1) echo "style='text-decoration:underline'"; ?>>我的课程</td>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=2"; ?>" <?php if($open==2) echo "style='text-decoration:underline'"; ?>>课程查询</td>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?open=3"; ?>" <?php if($open==3) echo "style='text-decoration:underline'"; ?>>修改密码</td>
      <td><a href="<?php echo $_SERVER['PHP_SELF']."?doLogout=true"; ?>">注销</td>
    </tr>
  </table>
  <p>&nbsp;</p>
  <div id="sc">

    <p>选课栏</p>
    <form id="form1" name="form1" method="post" action="">
      <p>
        <label for="c_id">课程号：</label>
        <input type="text" name="c_id" id="c_id" style="width:150px" />
      </p>
      <p>
        <input type="button" name="select" id="select" value="选课" onclick="return Select(form1)" />&nbsp;&nbsp;&nbsp;
        <input type="button" name="cancel" id="cancel" value="退课" onclick="return Cancel(form1)" />
		<input type="hidden" name="MyForm" value="" />
      </p>
    </form>
    <p>&nbsp; </p>
  </div>
  <div id="right">
	<?php
		echo $Myiframe;
	?>
  </div>
</div>
</body>
</html>
