<?php
include_once('./conn/db.php');
function getRedirectUrl ($url) {
  stream_context_set_default(array(
                             'http' => array(
                                             'method' => 'HEAD'
                                             )
                             ));
  $headers = get_headers($url, 1);
  stream_context_set_default(array(
                             'http' => array(
                                             'method' => 'GET'
                                             )
                             ));
  if ($headers !== false && isset($headers['Location'])) {
    return $headers['Location'];
  }
  return $url;
}
if(!session_id()) {
  session_start();
  date_default_timezone_set('Asia/Singapore');
}
if (!isset($_SESSION['name'])) {
  header("Location: index.php");
  die();
}
if (isset($_GET['upload']) && isset($_POST['url'])) {
  $url = $_POST['url'];
  if (!filter_var($url, FILTER_VALIDATE_URL) === false && preg_match("/^https?:\/\/.*\.jpg$/", $url)) {
    $url = getRedirectUrl($url);
    echo file_get_contents($url);
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
              <form id="register" method="post" action="?upload">
                <p class="heavy">
                  <div class="row center-align">
                    <p class="center">
                      .jpg files only.
                    </p>
                  </div>
                  <div class="row">
                    <center>
                      <div class="input-field col s9">
                        <input id="url" name="url" type="text" class="validate" required>
                        <label for="url">URL</label>
                      </div>
                      <div class="col s1">
                        <button style="margin-top:30px;" class="btn waves-effect waves-light brown" type="submit" name="action">Upload <i class="material-icons right">send</i>
                        </button>
                      </div>
                    </center>
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
