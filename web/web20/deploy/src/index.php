<?php
/*
 * flag is in /flag_is_here.lol 
 */
if(!session_id()) {
  session_start();
  date_default_timezone_set('Asia/Singapore');
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
        <br><br>
        <h1 class="header center light-blue-text">The Continental</h1>
        <div class="row center">
            <h5 class="header col s12 light">We only accept gold coins.</h5>
        </div>
        <div class="row center">
            <a href="login.php" id="download-button" class="btn-large waves-effect waves-light brown">Login</a>
        </div>
        <br><br>

    </div>
</div>


<div class="container">
    <div class="section">

        <!--   Icon Section   -->
        <div class="row">
            <div class="col s12 m4">
                <div class="icon-block">
                    <h2 class="center brown-text"><i class="material-icons">report_problem</i></h2>
                    <h5 class="center">No business in the hotel.</h5>
                </div>
            </div>

            <div class="col s12 m4">
                <div class="icon-block">
                    <h2 class="center brown-text"><i class="material-icons">local_hospital</i></h2>
                    <h5 class="center">24/7 Doctor</h5>
                </div>
            </div>

            <div class="col s12 m4">
                <div class="icon-block">
                    <h2 class="center brown-text"><i class="material-icons">hotel</i></h2>
                    <h5 class="center">Discrete</h5>
                </div>
            </div>
        </div>

    </div>
    <br><br>

    <div class="section">

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
