<?php require_once('../Connection/MySql.php')?>
<?php require_once('../all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>课程</title>
<link href="../style.css" rel="stylesheet" type="text/css" />
<style type="text/css">
#center {
	text-align: center;
}
</style>
</head>
<?php
	if($_SESSION['level'] == 2)
	{
		$t_id = $_SESSION['id'];
		
	}else Out_error();
	if(isset($_GET['del']))
	{
		/*
		$insertSQL = sprintf("delete from courses where id=%s",GetSQLValueString($_GET['del'],"text"));
		$result = mysql_query($insertSQL,$MySql);
		*/
		DeleteCourse($_GET['del']);
	}
	
	
?>
<script type="text/javascript">
	function del(url)
	{
		if(confirm('此操作将会删除本条记录，是否继续？'))
		{
			self.location = url;
		}
	}
	
	function modify(url)
	{
		window.open(url,'','width=520,height=600,toolbar=no, status=no, menubar=no, location=no, resizable=yes, scrollbars=yes');
	}
</script>
<body>
<div id="center">
  <table align="center" width="700" border="1" cellspacing="0px"  style="border-collapse:collapse">
    <tr>
      <td width="50">ID</td>
      <td width="200">课程名</td>
      <td width="50">教室</td>
      <td width="50">容量</td>
      <td width="50">人数</td>
      <td width="100">时间</td>
      <td width="200" colspan="2">操作</td>
    </tr>
	<?php
		if($_SESSION['level'] == 2):
			$insertSQL = sprintf("select * from courses where t_id=%d",GetSQLValueString($t_id,"int"));
			$result = mysql_query($insertSQL,$MySql);
			while($info = mysql_fetch_array($result))
			{
	?>
    <tr>
      <td width="50"><?php echo $info['id'] ?></td>
      <td width="200"><?php echo $info['name'] ?></td>
      <td width="50"><?php echo $info['room'] ?></td>
      <td width="50"><?php echo $info['maxnum'] ?></td>
      <td width="50"><?php echo $info['num'] ?></td>
      <td width="100"><a href="javascript:modify(<?php echo "'"."coursetime.php?id=".$info['id']."'"; ?>)">查看</td>
      <td width="100"><a href="javascript:modify(<?php echo "'"."course_modify.php?id=".$info['id']."'"; ?>)">详细信息</td>
      <td width="100"><a href="javascript:del(<?php echo "'".$_SERVER['PHP_SELF']."?del=".$info['id']."'"; ?>)">删除</td>
    </tr>
	<?php
		}
		endif;
	?>
  </table>
</div>
</body>
</html>
