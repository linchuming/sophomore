<?php require_once('Connection/MySql.php'); ?>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
</head>

<?php
	$db_seleted = mysql_select_db(SAE_MYSQL_DB,$MySql);
	if($db_seleted) echo "���ݿ�ѡ��ɹ���<br>";
	
	$result = mysql_query("create table students(
	id int,
	name varchar(16) not null,
	password char(32) not null,
	checked int,
	primary key(id))",$MySql);
	if($result) echo "������students�ɹ���<br>";
	
	$result = mysql_query("create table teachers(
	id int,
	name varchar(16) not null,
	password char(32) not null,
	faculty varchar(16) not null,
	checked int,
	primary key(id))",$MySql);
	if($result) echo "������teachers�ɹ���<br>";

	$result = mysql_query("create table managers(
	id int,
	name varchar(16) not null,
	password char(32) not null,
	primary key(id))",$MySql);
	if($result) echo "������managers�ɹ���<br>";
	
	$result = mysql_query("create table courses(
	id varchar(16),
	name varchar(16) not null,
	room varchar(8) not null,
	maxnum int,
	num int,
	t_id int,
	primary key(id),
	foreign key(t_id) references teachers(id))",$MySql);
	if($result) echo "������courses�ɹ���<br>";
	
	$result = mysql_query("create table sc(
	s_id int,
	c_id int,
	primary key(s_id,c_id),
	foreign key(s_id) references students(id),
	foreign key(c_id) references courses(id))",$MySql);
	if($result) echo "������sc�ɹ���<br>";
	
	$result = mysql_query("create table times(
	id varchar(16),
	days int,
	begin int,
	end int,
	primary key(id,days,begin),
	foreign key(id) references courses(id))",$MySql);
	if($result) echo "������times�ɹ���<br>";
?>