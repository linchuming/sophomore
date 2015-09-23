<?php require_once('../Connection/MySql.php')?>
<?php require_once('../all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>教师信息</title>
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
	if(isset($_GET['del']))
	{
		$insertSQL = sprintf("select checked from teachers where id=%d",GetSQLValueString($_GET['del'],"int"));
		$result = mysql_query($insertSQL,$MySql);
		$info = mysql_fetch_array($result);
		if(!isset($info) || $info == 0)
		{
			Out_error();
		}
		/*
		$insertSQL = sprintf("delete from teachers where id=%d",GetSQLValueString($_GET['del'],"int"));
		$result = mysql_query($insertSQL,$MySql);
		*/
		DeleteTeacher($_GET['del'],$MySql);
	}
	
?>
<script type="text/javascript">
	function del(url)
	{
		if(confirm('不通过将会删除本条记录，是否继续？'))
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
  <table align="center" width="600" border="1" cellspacing="0px"  style="border-collapse:collapse">
    <tr>
      <td width="100">ID</td>
      <td width="100">姓名</td>
	  <td width="200">院系</td>
      <td width="200" colspan="2">操作</td>
    </tr>
    <?php
    	$result = mysql_query("select id,name,faculty from teachers where checked=1",$MySql);
		while($info = mysql_fetch_array($result)){
    ?>
    <tr>
      <td width="100"><?php echo $info['id']; ?></td>
      <td width="100"><?php echo $info['name']; ?></td>
	  <td width="200"><?php echo $info['faculty']; ?></td>
      <td width="100"><a href="javascript:modify(<?php echo "'"."tea_modify.php?id=".$info['id']."'"; ?>)">修改</td>
      <td width="100"><a href="javascript:del(<?php echo "'".$_SERVER['PHP_SELF']."?del=".$info['id']."'"; ?>)">删除</td>
    </tr>	
    <?php
		}
    ?>
  </table>
</div>
</body>
</html>
