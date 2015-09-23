<?php require_once('Connection/MySql.php'); ?>
<?php require_once('all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>课程查询</title>
<link href="../style.css" rel="stylesheet" type="text/css" />
</head>
<?php
	if(!isset($_SESSION['level'])) Out_error();
	$flag = false;
	if($_POST['MyForm'] == "form1")
	{
		$flag = true;
		if($_POST['faculty']=="0")
		{
			$insertSQL = sprintf("select * from courses where id like %s",
						GetSQLValueString($_POST['c_id']."%","text"));
			
			$result = mysql_query($insertSQL,$MySql);
		}else{
			$insertSQL = sprintf("select courses.id,courses.room,courses.name,courses.maxnum,courses.num,courses.t_id 
								from courses,teachers where courses.t_id=teachers.id and teachers.faculty=%s and courses.id like %s",
								GetSQLValueString($_POST['faculty'],"text"),
								GetSQLValueString($_POST['c_id']."%","text"));
			$result = mysql_query($insertSQL,$MySql);
		}
		
	}
?>
<body>
<form id="form1" name="form1" method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
  <label for="c_id">课程号：</label>
  <input type="text" name="c_id" id="c_id" />
  &nbsp;&nbsp;&nbsp;
  <label for="faculty">院系：</label>
  <select name="faculty" id="faculty">
    <option value="0" selected="selected">所有</option>
    <option value="计算机科学与技术">计算机科学与技术</option>
    <option value="微电子科学与技术">微电子科学与技术</option>
    <option value="中文系">中文系</option>
  </select>
  &nbsp;&nbsp;&nbsp;
  <input type="submit" name="button" id="button" value="查询" />
  <input type="hidden" name="MyForm" value="form1" />
</form>
<p> </p>
<table width="100%" border="1" cellspacing="0px"  style="border-collapse:collapse">
  <tr>
    <td>课程号</td>
    <td>名称</td>
    <td width="10%">教师</td>
    <td width="10%">教室</td>
    <td width="5%">容量</td>
    <td width="5%">当前人数</td>
    <td>时间</td>
  </tr>
<?php
	if($flag):
		while($info = mysql_fetch_array($result))
		{
			$insertSQL = sprintf("select name from teachers where id=%d",GetSQLValueString($info['t_id'],"int"));
			$p_result = mysql_query($insertSQL,$MySql);
			$tea = mysql_fetch_array($p_result);
			$teacher_name = $tea['name'];
			$time = "";
			$insertSQL = sprintf("select * from times where id=%s",GetSQLValueString($info['id'],"text"));
			$p_result = mysql_query($insertSQL);
			while($msg = mysql_fetch_array($p_result))
			{
				if($msg['begin'] == $msg['end'])
				{
					$time = $time.$days[$msg['days']]."第".$msg['begin']."节"."<br>";
				}else{
					$time = $time.$days[$msg['days']]."第".$msg['begin']."节"."到第".$msg['end']."节"."<br>";
				}
			}
?>
    <td><?php echo $info['id']; ?></td>
    <td><?php echo $info['name']; ?></td>
    <td width="10%"><?php echo $teacher_name; ?></td>
    <td width="10%"><?php echo $info['room']; ?></td>
    <td width="5%"><?php echo $info['maxnum']; ?></td>
    <td width="5%"><?php echo $info['num']; ?></td>
    <td><?php echo $time; ?></td>
  </tr>
<?php
		}
	endif;
?>
</table>
</body>
</html>
