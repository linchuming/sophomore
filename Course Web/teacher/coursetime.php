<?php require_once('../Connection/MySql.php')?>
<?php require_once('../all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>课程时间设置</title>
<link href="../style.css" rel="stylesheet" type="text/css" />
</head>
<script type="text/javascript">
	function del(url)
	{
		if(confirm('是否要删除本条记录？'))
		{
			self.location = url;
		}
	}
	function check(form)
	{
		if(form.begin.value == "" || form.end.value == "")
		{
			alert("请填写完整！"); return false;
		}
		var u1 = parseInt(form.begin.value);
		var u2 = parseInt(form.end.value);
		if(u1>14 || u2>14)
		{
			alert("填写范围应在0~14！"); return false;
		}
		if(u1 > u2)
		{
			alert("填写数据有误，请检查！"); return false;
		}
		form.submit();
	}
</script>
<?php
	$c_id = $_GET['id'];
	if($_SESSION['level'] == 2)
	{
		$insertSQL = sprintf("select t_id from courses where id=%s",GetSQLValueString($c_id,"text"));
		$result = mysql_query($insertSQL,$MySql);
		$info = mysql_fetch_array($result);
		if($info['t_id']!=$_SESSION['id']) Out_error();
	
		if(isset($_GET['del1']) && isset($_GET['del2']))
		{
			$insertSQL = sprintf("delete from times where id=%s and days=%d and begin=%d",
								GetSQLValueString($c_id,"text"),
								GetSQLValueString($_GET['del1'],"int"),
								GetSQLValueString($_GET['del2'],"int"));
			$result = mysql_query($insertSQL,$MySql);
			urlgoto($_SERVER['PHP_SELF']."?id=".$c_id);
			return;
								
		}
		
		if($_POST['MyForm'] == "form1")
		{
			$insertSQL = sprintf("insert into times(id,days,begin,end) values(%s,%d,%d,%d)",
								GetSQLValueString($c_id,"text"),
								GetSQLValueString($_POST['days'],"int"),
								GetSQLValueString($_POST['begin'],"int"),
								GetSQLValueString($_POST['end'],"int"));
			$result = mysql_query($insertSQL,$MySql);
		}
		
	}else Out_error();
?>
<body>
<table width="350" border="1" cellspacing="0px"  style="border-collapse:collapse">
  <tr>
    <td width="100">时间</td>
    <td width="100">开始节数</td>
    <td width="100">结束节数</td>
    <td width="50">操作</td>
  </tr>
  <?php
	$insertSQL = sprintf("select * from times where id=%s",GetSQLValueString($c_id,"text"));
	$result = mysql_query($insertSQL,$MySql);
	while($info = mysql_fetch_array($result))
	{
  ?>
  <tr>
    <td width="100"><?php echo $days[$info['days']]; ?></td>
    <td width="100"><?php echo "第".$info['begin']."节"; ?></td>
    <td width="100"><?php echo "第".$info['end']."节"; ?></td>
    <td width="50"><a href="javascript:del(<?php echo "'".$_SERVER['PHP_SELF']."?id=".$info['id']."&del1=".$info['days']."&del2=".$info['begin']."'"; ?>)">删除</td>
  </tr>
  <?php
	}
  ?>
</table>
<form id="form1" name="form1" method="post" action="<?php echo $_SERVER['PHP_SELF']."?id=".$c_id; ?>">
  <label for="days"></label>
  <select name="days" id="days">
    <option value="1">周一</option>
    <option value="2">周二</option>
    <option value="3">周三</option>
    <option value="4">周四</option>
    <option value="5">周五</option>
    <option value="6">周六</option>
    <option value="7">周日</option>
  </select>
  <label for="begin">开始节数</label>
  <input type="text" style="width:50px" name="begin" id="begin"  />
   <label for="end">结束节数</label>
  <input type="text" style="width:50px" name="end" id="end"  />
  
  <input type="submit" name="button" id="button" value="添加" onclick="return check(form1)" />
  <input type="hidden" name="MyForm" value="form1" />
</form>
<p>&nbsp;</p>
</body>
</html>
