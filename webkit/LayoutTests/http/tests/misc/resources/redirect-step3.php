<?php
  // Test for various syntaxes of Refresh header, 
  // <http://bugzilla.opendarwin.org/show_bug.cgi?id=9854>.

  header('Content-type: text/html');
?>
<head>
  <meta http-equiv="Refresh" content=" 0, 'redirect-step4.php' ">
</head>

<p>FAILURE - should redirect (3)<p>
