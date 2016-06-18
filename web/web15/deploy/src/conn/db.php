<?php
class dbConn {
  private $conn;
  public function __construct() {
    $dbhost = 'localhost';
    $dbuser = 'continental';
    $dbpass = 'XCTFP@SSW0RDV3RYL0NGANDG00DANDVERYLONG';
    $dbname = 'continental';
    $this->conn = new mysqli($dbhost, $dbuser, $dbpass, $dbname) or die("Wrong info given");
    if (mysqli_connect_errno()) {
      exit();
    }
  }

  public function getConn() {
    return $this->conn;
  }


  public function clearResult() {
    while ($this->conn->more_results() && $this->conn->next_result()) {
      $result = $this->conn->use_result();
      if ($result instanceof mysqli_result) {
        $result->free();
      }
    }
  }

  public function getAllUsernameLike($username) {
    $return = array();
    $sql = "SELECT username FROM users WHERE username like '%".$username."%';";
    if ($this->conn->multi_query($sql)) {
      $result = $this->conn->store_result();
      while ($row = $result->fetch_array()) {
        array_push($return, $row);   
      }
      $this->conn->close();
      if ( empty($return) ) {
        return null;
      } else {
        return $return;
      }
    } else {
      $this->conn->close();
      return false;
    }
  }

  public function checkLogin($username, $password) {
    $username = $this->conn->real_escape_string($username);
    $password = $this->conn->real_escape_string($password);
    $sql = "SELECT * FROM users WHERE username = '$username' AND password = MD5('$password');";
    if ($this->conn->multi_query($sql)) {
      $result = $this->conn->store_result();
      $row = $result->fetch_array();
      $this->conn->close();
      return $row;
    } else {
      $this->conn->close();
      return false;
    }
  }

  public function createNewUser($username, $password) {
    $username = $this->conn->real_escape_string($username);
    $password = $this->conn->real_escape_string($password);
    $sql = "INSERT INTO users VALUES (null, '".$username."', MD5('".$password."'), '', 0);";
    if ($this->conn->multi_query($sql)) {
      $id = mysqli_insert_id($this->conn);
      $this->conn->close();
      return $id;
    } else {
      $this->conn->close();
      return false;
    }
  }

  public function doesUsernameExist($username) {
    $username = $this->conn->real_escape_string($username);
    $sql = "SELECT * from users where username = '".$username."';";
    if ($this->conn->multi_query($sql)) {
      $result = $this->conn->store_result();
      $row = $result->fetch_array();
      $this->conn->close();
      return sizeof($row)>0;
    } else {
      $this->conn->close();
      return false;
    }
  }
}
?>