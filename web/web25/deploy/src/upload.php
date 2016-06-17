<?php
include_once('./conn/db.php');
$scheme = ["ftp", "zlib", "data", "glob", "phar", "ssh2", "rar", "ogg", "php","https","http","ftps","compress.zlib","compress.bzip2","zip"];
foreach ($scheme as $i) {
  stream_wrapper_unregister($i);
}

if(!session_id()) {
  session_start();
  date_default_timezone_set('Asia/Singapore');
}
if (!isset($_SESSION['name'])) {
  header("Location: index.php");
  die();
}
if (isset($_GET['upload']) && isset($_FILES['image'])) {

  $allowed =  array('gif', 'png' ,'jpg');
  $filename = $_FILES['image']['name'];
  $ext = pathinfo($filename, PATHINFO_EXTENSION);
  if(in_array($ext,$allowed) ) {
    $contents = file_get_contents($_FILES["image"]["tmp_name"]);
    $name = md5($_POST['username']);
    $url = "./hitimages/" . $name . "_" . $_POST['username'] . ".jpg";
    $imageFile = fopen($url,"wb");
    if ($imageFile) {
      fwrite($imageFile, $contents);
      $file = $url;
      fclose($imageFile);
    }
  } else if ($ext === 'svg') {
    $svg = file_get_contents($_FILES["image"]["tmp_name"]);
    $svg = new SimpleXMLElement( $svg );
    $svg->registerXPathNamespace('svg', 'http://www.w3.org/2000/svg');
    $svg->registerXPathNamespace('xlink', 'http://www.w3.org/1999/xlink');
    $result = $svg->xpath('//svg:image/@xlink:href');

    $msg = "";
    for ($i = 0; $i < count($result); $i++){
      $msg .= file_get_contents($result[$i]['href']);
    }
  }

}

?>
<!DOCTYPE html>
<html lang="en">
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=UTF-8"/>
  <meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1.0"/>
  <title>The Continental</title>

  <!-- CSS  -->
  <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
  <link href="css/materialize.css" type="text/css" rel="stylesheet" media="screen,projection"/>
  <link href="css/style.css" type="text/css" rel="stylesheet" media="screen,projection"/>
</head>
<body>
  <nav class="light-blue lighten-1" role="navigation">
    <div class="nav-wrapper container"><a id="logo-container" href="#" class="brand-logo"></a>
      <ul class="right hide-on-med-and-down">
        <?php
        if ($_SESSION['name']) {
          echo '<li><a href="upload.php">Record your hits</a></li>';
        }
        ?>
        <li><a href="index.php">Home</a></li>
        <?php 
        if ($_SESSION['name']) {
          echo '<li><a href="login.php?logout">'.$_SESSION['name'].'</a></li>';
        } else {
          echo '<li><a href="login.php">Login</a></li>';
        }
        ?>
      </ul>

      <ul id="nav-mobile" class="side-nav">
        <?php
        if ($_SESSION['name']) {
          echo '<li><a href="upload.php">Record your hits</a></li>';
        }
        ?>
        <li><a href="index.php">Home</a></li>
        <?php
        if (isset($_SESSION['name'])) {
          echo '<li><a href="login.php?logout">'.$_SESSION['name'].'</a></li>';
        } else {
          echo '<li><a href="login.php">Login</a></li>';
        }
        ?>
      </ul>
      <a href="#" data-activates="nav-mobile" class="button-collapse"><i class="material-icons">menu</i></a>
    </div>
  </nav>
  <div class="section no-pad-bot" id="index-banner">
    <div class="container">
      <div class="section">
        <!--   Icon Section   -->
        <div class="row">
          <div class="col s1 m1">
            &nbsp;
          </div>
          <div class="col s10 m10">
            <div class="icon-block">
              <h5 class="center">Upload your hit image:</h5>
              <form id="register" method="post" enctype="multipart/form-data" action="?upload">
                <p class="heavy">
                  <div class="row">
                    <center>
                      <div class="input-field col">
                        <input id="image" name="image" type="file" class="validate" required>
                      </div>
                    </center>
                  </div>
                  <div class="row">
                    <center>
                      <div class="col">
                        <button style="margin-top:30px;" class="btn waves-effect waves-light brown" type="submit" name="action">Upload <i class="material-icons right">send</i>
                        </button>
                      </div>
                    </center>
                  </div>
                  <div class="row center-align">
                    <p class="center">
                      <?php
                      if (isset($file)) {
                        echo "<img src=$file width='500px' height='500px'>";
                      }
                      else if (isset($msg)) {
                        echo "Secret mode activated:<br/>";
                        echo "<p><code><pre>$msg</pre></code></p>";
                      }
                      ?>
                    </p>
                  </div>
                </p>  
              </form>
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>

  <footer class="page-footer light-blue">
    <div class="container">
      <div class="row">
        <div class="col l6 s12">
          <h5 class="white-text">The Continental</h5>
          <p class="grey-text text-lighten-4">Hotel for assassins</p>
        </div>
      </div>
    </div>
    <div class="footer-copyright">
      <div class="container">
        Made by <a class="orange-text text-lighten-3" href="http://materializecss.com">Materialize</a>
      </div>
    </div>
  </footer>


  <!--  Scripts-->
  <script src="https://code.jquery.com/jquery-2.1.1.min.js"></script>
  <script src="js/materialize.js"></script>
  <script src="js/init.js"></script>

</body>
</html>
