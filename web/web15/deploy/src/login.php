<?php
include_once('./conn/db.php');

if(!session_id()) {
  session_start();
  date_default_timezone_set('Asia/Singapore');
}

if (isset($_SESSION['name'])) {
  if (isset($_GET['logout'])) {
    session_destroy();
    if (ini_get('session.use_cookies')) {
      $params = session_get_cookie_params();
      setcookie(
                session_name(),
                '',
                time() - 42000,
                $params['path'], $params['domain'],
                $params['secure'], $params['httponly']
                );
    }
  }
  header("Location: index.php");
  die();
}

$connObj = new dbConn();

if (isset($_GET['register']) && isset($_POST['username'])) {
  if ($connObj->doesUsernameExist($_POST['username'])) {
    $error = "Username exists.";
  } else {
    if (isset($_POST['password']) && isset($_POST['confirm-password']) && $_POST['password'] == $_POST['confirm-password']) {
      $connObj = new dbConn();
      if ($connObj->createNewUser($_POST['username'],$_POST['password'])) {
        $status = "Successfully created account!";
      } else {
        $error = "An error occurred!";
      }
    } else {
      $error = "Passwords do not match!";
    }
  }
} else if (isset($_GET['login'])) {
  if (isset($_POST['username']) && isset($_POST['password'])) {
    $connObj = new dbConn();
    if ($result = $connObj->checkLogin($_POST['username'], $_POST['password'])) {
      $_SESSION['name'] = htmlspecialchars($_POST['username'], ENT_QUOTES, 'UTF-8');
      $_SESSION['is_admin'] = $result['isAdmin'];
      header("Location: index.php");
      die();
    } else {
      $login_error = "Login failed.";
    }
  }}
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
          <li><a href="index.php">Home</a></li>
          <li><a href="login.php">Login</a></li>
        </ul>

        <ul id="nav-mobile" class="side-nav">
          <li><a href="index.php">Home</a></li>
          <li><a href="login.php">Login</a></li>
        </ul>
        <a href="#" data-activates="nav-mobile" class="button-collapse"><i class="material-icons">menu</i></a>
      </div>
    </nav>
    <div class="section no-pad-bot" id="index-banner">
      <div class="container">
        <div class="section">
          <!--   Icon Section   -->
          <div class="row">
            <div class="col s12 m6">
              <div class="icon-block">
                <h2 class="center brown-text"><i class="material-icons">loyalty</i></h2>
                <h5 class="center">Create an Account</h5>
                <form id="register" method="post" action="?register">
                  <p class="heavy">
                    <div class="status" style="text-align:center;">
                      <?php
                      if (isset($status)) {
                        echo $status;
                      } else {
                        echo 'Username has to be 30 characters or lesser.';
                      }
                      ?>
                    </div>
                    <div class="error" style="text-align:center;color:red">
                      <?php 
                      if (isset($error)) {
                        echo $error;
                      }
                      ?>
                    </div>
                    <div class="input-field col s12">
                      <input id="Username" name="username" type="text" class="validate" required>
                      <label for="Username">Username</label>
                    </div>
                    <div class="input-field col s6">
                      <input id="password" name="password" type="password" class="validate" required pattern=".{5,}">
                      <label style="width:100%" for="password" data-error="Too short! 5 characters minimum.">Password</label>
                    </div>
                    <div class="input-field col s6">
                      <input id="confirm-password" name="confirm-password" type="password" class="validate" required pattern=".{5,}">
                      <label style="width:100%" for="confirm-password" data-error="Too short! 5 characters minimum.">Confirm Password</label>
                    </div>
                    <center>
                      <button style="margin-top:30px;" class="btn waves-effect waves-light brown" type="submit" name="action">Submit
                        <i class="material-icons right">send</i>
                      </button>
                    </center>
                  </p>  
                </form>
              </div>
            </div>

            <div class="col s12 m6">
              <div class="icon-block">
                <h2 class="center brown-text"><i class="material-icons">supervisor_account</i></h2>
                <h5 class="center">Login</h5>
                <form id="loginform" method="post" action="?login">
                  <p class="heavy">
                    <div class="error" style="text-align:center;color:red">
                      <?php 
                      if (isset($login_error)) {
                        echo $login_error;
                      }
                      ?>
                    </div>
                    <div class="input-field col s12">
                      <input id="Username" name="username" type="text" class="validate" required>
                      <label for="Username">Username</label>
                    </div>
                    <div class="input-field col s12">
                      <input id="login-password" name="password" type="password" class="validate" required pattern=".{5,}">
                      <label style="width:100%" for="login-password" data-error="Too short! 5 characters minimum.">Password</label>
                    </div>
                    <br/>
                    <center>
                      <button class="btn waves-effect waves-light brown" type="submit" name="action">Login
                        <i class="material-icons right">send</i>
                      </button>
                    </center>
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
