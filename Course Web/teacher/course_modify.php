<?php require_once('../Connection/MySql.php')?>
<?php require_once('../all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>课程信息</title>
<link href="../style.css" rel="stylesheet" type="text/css" />
<style type="text/css">
#main {
	width: 400px;
}
</style>
</head>
<?php
	$c_id = $_GET['id'];
	if($_SESSION['level'] == 2)
	{
		$insertSQL = sprintf("select * from courses where id=%s",GetSQLValueString($c_id,"text"));
		$result = mysql_query($insertSQL,$MySql);
		$info = mysql_fetch_array($result);
		if($info['t_id']!=$_SESSION['id']) Out_error();	

		if($_POST['MyForm'] == "form1")
		{
			$insertSQL = sprintf("update courses set name=%s,maxnum=%d where id=%s",
						GetSQLValueString($_POST['name'],"text"),
						GetSQLValueString($_POST['maxnum'],"int"),
						GetSQLValueString($c_id,"text"));
			$result = mysql_query($insertSQL,$MySql);
			if($result) 
			{
				shell_js("alert('修改课程信息成功！');");
				urlgoto($_SERVER['PHP_SELF']."?id=".$c_id);
			}
		}
		if($_POST['MyForm'] == "form2")
		{
			$insertSQL = sprintf("select id from students where id=%d",GetSQLValueString($_POST['stu_id'],"int"));
			$result = mysql_query($insertSQL,$MySql);
			$info1 = mysql_fetch_array($result);
			if($info1 != false)
			{
				$insertSQL = sprintf("insert into sc(s_id,c_id) values(%d,%s)",
							GetSQLValueString($_POST['stu_id'],"int"),
							GetSQLValueString($c_id,"text"));
				$result = mysql_query($insertSQL,$MySql);
				if($result)
				{
					$insertSQL = sprintf("update courses set num=num+1 where id=%s",GetSQLValueString($c_id,"text"));
					mysql_query($insertSQL);
					shell_js("alert('添加学生成功！');");
				}
			}else{
				shell_js("alert('该学生不存在！');");
			}
		}
		
		if(isset($_GET['del']))
		{
			$insertSQL = sprintf("delete from sc where s_id=%d and c_id=%s",
								GetSQLValueString($_GET['del'],"int"),
								GetSQLValueString($c_id,"text"));
			$result = mysql_query($insertSQL,$MySql);
			$insertSQL = sprintf("update courses set num=num-1 where id=%s",GetSQLValueString($c_id,"text"));
			mysql_query($insertSQL);
			urlgoto($_SERVER['PHP_SELF']."?id=".$c_id);
			return;
		}
	}else Out_error();
?>
<script type="text/javascript">
	function check1(form)
	{
		if(form.name.value == "" || form.maxnum.value == "")
		{
			alert("输入数据有误，请检查！"); return false;
		}
		form.submit();
	}
	function check2(form)
	{
		if(form.stu_id.value == "")
		{
			alert("请输入学生ID！"); return false;
		}
		form.submit();
	}
	function del(url)
	{
		if(confirm('是否将该学生踢出本门课程？'))
		{
			self.location = url;
		}
	}
</script>
<body>
<form id="form1" name="form1" method="post" action="<?php echo $_SERVER['PHP_SELF']."?id=".$c_id; ?>">
  <p>
    <label for="name">课名：</label>
    <input type="text" name="name" id="name" value="<?php echo $info['name'];?>" style="width:150px" />
    <label for="maxnum">容量：</label>
    <input type="text" name="maxnum" id="maxnum" value="<?php echo $info['maxnum'];?>" style="width:50px"/>
    <input type="submit" name="button1" id="button1" value="修改" onclick="return check1(form1)" />
	<input type="hidden" name="MyForm" value="form1" />
  </p>
</form>
<form id="form2" name="form2" method="post" action="<?php echo $_SERVER['PHP_SELF']."?id=".$c_id; ?>">
  <label for="stu_id">学生ID：</label>
  <input type="text" name="stu_id" id="stu_id" />
  <input type="submit" name="button2" id="button2" value="添加学生" onclick="return check2(form2)" />
  <input type="hidden" name="MyForm" value="form2" />
</form>
<div id="main">
  <p align="center">本课程学生信息</p>
  <table width="400" border="1" cellspacing="0px"  style="border-collapse:collapse">
    <tr>
      <td>ID</td>
      <td>姓名</td>
      <td>操作</td>
    </tr>
	<?php
		$insertSQL = sprintf("select students.id,students.name from students,sc where sc.s_id = students.id and sc.c_id=%s",
							GetSQLValueString($c_id,"text"));
		$result = mysql_query($insertSQL,$MySql);
		while($stu = mysql_fetch_array($result))
		{
	?>
    <tr>
      <td><?php echo $stu['id']; ?></td>
      <td><?php echo $stu['name']; ?></td>
      <td><a href="javascript:del(<?php echo "'".$_SERVER['PHP_SELF']."?id=".$c_id."&del=".$stu['id']."'"; ?>)">退课</td>
    </tr>
	<?php
		}
	?>
  </table>
  <p>&nbsp;</p>
</div>
<p>&nbsp;</p>
</body>
</html>
