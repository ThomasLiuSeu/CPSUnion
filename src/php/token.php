<?php header('Access-Control-Allow-Origin:*');
    $user_id = $_GET["uid"] ;
    if (is_numeric($user_id )) 
    {
      $md5 = base_convert(md5($user_id), 16, 10 );
      $token = base64_encode($md5 & 0xffff0000 + $user_id );
      echo $token;
      exit();
    }
    $token = $_GET["token"] ;
    if (!empty($token )) 
    {
       $decode = base64_decode($token);
       if (is_numeric($decode )) 
      {
         $user_id = $decode & 0x0000ffff;
         if ($token == base64_encode(base_convert(md5($user_id), 16, 10 )  & 0xffff0000 + $user_id)) 
         {
            echo $user_id;
            exit(); 
         }
      }
      echo "Token is not correct";
      exit(); 
    }
?>

