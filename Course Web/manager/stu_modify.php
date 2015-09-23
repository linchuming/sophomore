<?php require_once('../Connection/MySql.php')?>
<?php require_once('../all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>学生修改</title>
<link href="../style.css" rel="stylesheet" type="text/css" />
</head>
<?php
	$id = $_GET['id'];
	if($_SESSION['level'] != 3 || !isset($id))
    {
    	Out_error();
    }
	if($_POST['MyForm'] == "form1")
	{
		$insertSQL = sprintf("update students set name=%s where id=%d",
			GetSQLValueString($_POST['name'],"text"),
			GetSQLValueString($id,"int"));
		$result = mysql_query($insertSQL,$MySql);
		if($result) shell_js("alert('修改成功！');");
	}
	$insertSQL = sprintf("select name from students where id=%d",GetSQLValueString($id,"int"));
	$result = mysql_query($insertSQL,$MySql);
	$info = mysql_fetch_array($result);
	if(!isset($info)) Out_error();
	
?>
<script type="text/javascript">
function check(form)
{
	if(form.name.value == "")
	{
		alert("姓名不能为空！");
		form.name.focus(); return false;
	}
	form.submit();
} 
</script>
<body>
<div>
  <p>ID：&nbsp;<?php echo $id; ?></p>
  <form id="form1" name="form1" method="post" action="<?php echo $_SERVER['PHP_SELF']."?id=".$id; ?>">
  	<p>
    <label for="name">姓名： </label>
    <input type="text" name="name" id="name" width="100" value="<?php echo $info['name']; ?>" />
    </p>
    <input type="submit" name="login" id="login" value="修改" onclick="return check(form1)" />
    <input type="hidden" name="MyForm" value="form1" />
  </form>
</div>
</body>
</html>
