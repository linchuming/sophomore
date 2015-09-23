<?php require_once('../Connection/MySql.php')?>
<?php require_once('../all.php'); ?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<title>课程表</title>
<link href="../style.css" rel="stylesheet" type="text/css" />
<style type="text/css">
#center {
	text-align: center;
	font-family: "微软雅黑";
}
</style>
</head>
<?php
	if($_SESSION['level'] == 1)
	{
	}else Out_error();
?>
<body>
<div id="center">
  <table width="100%" border="1" id="table1" cellspacing="0px"  style="border-collapse:collapse">
    <tr>
      <td width="8%">周节</td>
      <td>周一</td>
      <td>周二</td>
      <td>周三</td>
      <td>周四</td>
      <td>周五</td>
      <td>周六</td>
      <td>周日</td>
    </tr>
    <tr>
      <td width="8%">第1节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td width="8%">第2节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
    <tr>
      <td width="8%">第3节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
     <tr>
      <td width="8%">第4节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
     <tr>
      <td width="8%">第5节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
     <tr>
      <td width="8%">第6节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
     <tr>
      <td width="8%">第7节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
      <tr>
      <td width="8%">第8节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
      <tr>
      <td width="8%">第9节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
      <tr>
      <td width="8%">第10节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
      <tr>
      <td width="8%">第11节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
      <tr>
      <td width="8%">第12节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
      <tr>
      <td width="8%">第13节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
       <tr>
      <td width="8%">第14节</td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
      <td></td>
    </tr>
  </table>
</div>
<script type="text/javascript">
	var arranges = new Array();
	var index = 0;
	<?php
		$insertSQL = sprintf("select courses.name,courses.id,courses.room,courses.t_id from sc,courses where sc.s_id=%d and sc.c_id = courses.id",
							GetSQLValueString($_SESSION['id'],"int"));
		$result = mysql_query($insertSQL,$MySql);
		while($info = mysql_fetch_array($result))
		{
			$course_name = $info['name'];
			$course_id = $info['id'];
			$course_room = $info['room'];
			$insertSQL = sprintf("select name from teachers where id=%d",GetSQLValueString($info['t_id'],"int"));
			$p_result = mysql_query($insertSQL);
			$tea = mysql_fetch_array($p_result); $teacher_name = $tea['name'];
			$content = $course_id."<br>".$course_name."<br>".$course_room."(".$teacher_name.")";
			$insertSQL = sprintf("select days,begin,end from times where id=%s",GetSQLValueString($course_id,"text"));
			$p_result = mysql_query($insertSQL);
			while($time = mysql_fetch_array($p_result))
			{
				$week = $time['days']; 
				$start = $time['begin'];
				$units = $time['end'] - $time['begin'] + 1;
	?>
	arranges[index] = new Object();
	arranges[index].week = <?php echo $week; ?>;
	arranges[index].start = <?php echo $start; ?>;
	arranges[index].units = <?php echo $units; ?>;
	arranges[index++].content = '<?php echo $content; ?>';
	<?php
			}
		}
	?>

	var tb = document.getElementById("table1");
	//var x = new Array();
	//for(var i=1;i<=14;i++) x[i] = 0;
	for(var i=0;i<index;i++)
	{
		var row = arranges[i].start;
		var col = arranges[i].week;
		tb.rows[row].cells[col].rowSpan = arranges[i].units;
		tb.rows[row].cells[col].innerHTML = arranges[i].content;
	}
	
	for(var i=0;i<index;i++)
	{
		var row = arranges[i].start;
		var col = arranges[i].week;
		for(var j = 1;j<arranges[i].units;j++)
		{
			tb.rows[row+j].removeChild(tb.rows[row+j].cells[col]);
		}
	}
</script>
</body>
</html>
