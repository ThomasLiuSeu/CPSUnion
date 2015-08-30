<%--
  Created by IntelliJ IDEA.
  User: LIUTH2
  Date: 7/10/14
  Time: 6:30 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
  <head>
    <script src="webroot/lib/jquery-2.0.2.js"></script>
    <link rel="stylesheet" type="text/css" href="webroot/css/main.css">
    <script>
        var mySite = "http://www.riertao.com/";
        <%--var mySite = this.location.href;--%>
        function submitClick () {
            var tempSite = this.mySite + "?";
            $.each($(".userInput"), function(idx, rec) {
                tempSite += rec.id + "=" + escape(rec.value||"") + "&";
            });
            if (tempSite.lastIndexOf('&') > 0) {
                tempSite = tempSite.substr(0 , tempSite.length - 1);
            }
            $("#result")[0].value = tempSite;
        }

        function onJump() {
            var destSite =  $("#result")[0].value;
            window.location.href = destSite;
        }
    </script>
    <title></title>
  </head>
  <body>
            URL <input type="text" id="url" class="userInput"><br>
            TAG <input type="text" id="tag" class="userInput"><br>
            User Id <input type="text" id="userId" class="userInput"><br>
            <input type="submit" value="计算URL" onclick="submitClick()">
            <br><br>
        <textarea id="result"></textarea><br>
        <input type="submit" value="跳转到生成的URL" onclick="onJump()">
  </body>
</html>