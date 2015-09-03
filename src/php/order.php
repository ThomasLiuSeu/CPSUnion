<?php
    $mysql_server_name="localhost"; //数据库服务器名称
    $mysql_username="root"; // 连接数据库用户名
    $mysql_password="abcdefg2008"; // 连接数据库密码
    $mysql_database="CPSUnion"; // 数据库的名字
    $user_id = $_GET["uid"] ;
    if (!is_numeric($user_id )) 
    {
        echo "User id is not correct";
        exit();
    }
    $status = $_GET["status"] ;
    if (!is_numeric($status ) && $status != "") 
    {
        echo "Status is not correct:".$status;
        echo "\nShould be 0,1,2,3,4,5";
        exit();
    }
    $begin_time = $_GET["begin_time"] ;
    if (!is_numeric($begin_time ) && $begin_time != "") 
    {
        echo "begin time is not correct:".$begin_time;
        exit();
    }
    $end_time = $_GET["end_time"] ;
    if (!is_numeric($end_time )  && $end_time != "") 
    {
        echo "end time time is not correct:".$end_time;
        exit();
    }
    $tags=$_GET["tags"] ;
    // 连接到数据库
    $conn=mysql_connect($mysql_server_name, $mysql_username, $mysql_password);
                        
     // 从表中提取信息的sql语句
    $strsql="SELECT * FROM `clicks` INNER JOIN `orders` ON clicks.click_id = orders.click_id where user_id=".$user_id;
    if ($tags != "") 
    {
        $strsql = $strsql." and tags=\"".$tags."\"";
    }
    if ($status != "") 
    {
        $strsql = $strsql." and status=\"".$status."\"";
    }
    if ($begin_time != "") 
    {
        $strsql = $strsql." and order_time>\"".$begin_time."\"";
    }
    if ($end_time != "") 
    {
        $strsql = $strsql." and order_time<\"".$end_time."\"";
    }
    // 执行sql查询
    $result=mysql_db_query($mysql_database, $strsql, $conn);
    // 获取查询结果
    $row=mysql_fetch_row($result);
    
     
    echo '<font face="verdana">';
    echo '<table border="1" cellpadding="1" cellspacing="2">';

    // 显示字段名称
    echo "</b><tr></b>";
    for ($i=0; $i<mysql_num_fields($result); $i++)
    {
      echo '<td><b>'.
      mysql_field_name($result, $i);
      echo "</b></td></b>";
    }
    echo "</tr></b>";
    // 定位到第一条记录
    mysql_data_seek($result, 0);
    // 循环取出记录
    while ($row=mysql_fetch_row($result))
    {
      echo "<tr></b>";
      for ($i=0; $i<mysql_num_fields($result); $i++ )
      {
        echo '<td >';
        echo $row[$i];
        echo '</td>';
      }
      echo "</tr></b>";
    }
   
    echo "</table></b>";
    echo "</font>";
    // 释放资源
    mysql_free_result($result);
    // 关闭连接
    mysql_close($conn);  
?>
