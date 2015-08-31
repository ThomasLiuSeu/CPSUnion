<?php
    $mysql_server_name="localhost"; //数据库服务器名称
    $mysql_username="root"; // 连接数据库用户名
    $mysql_password="abcdefg2008"; // 连接数据库密码
    $mysql_database="CPSUnion"; // 数据库的名字
    $user_id = $_GET["uid"] ;
    $tags=$_GET["tags"] ;
    $time= time();
    $click_id = base_convert(substr(md5($user_id."|".$tags."|".$time),8,16), 16, 10 );
    echo $click_id;
    // 连接到数据库
    $conn=mysql_connect($mysql_server_name, $mysql_username,
                        $mysql_password);
     // 从表中提取信息的sql语句
    $strsql="INSERT INTO `clicks`  values(".$click_id.",".$user_id.",".$time.",\"".$tags."\")";
    // 执行sql查询
    $result=mysql_db_query($mysql_database, $strsql, $conn);
    // 获取查询结果
    $row=mysql_fetch_row($result);
    // 释放资源
    mysql_free_result($result);
    // 关闭连接
    mysql_close($conn);  
?>
