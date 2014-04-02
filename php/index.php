<?php
// Create connection
$con=mysqli_connect("localhost","root","","test");

// Check connection
if (mysqli_connect_errno()) {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

$method = $_SERVER['REQUEST_METHOD'];
$bad_pass = false;
$show_text = false;
echo print_r(explode (':', "aaa:bbb"));

if ($method == "POST") {
  
  if (isset($_POST["ps"])) {
    $q="INSERT INTO site_users (name, password, birthday) VALUES ('" . $_POST["nm"] . "','" . sha1($_POST["ps"]) . "','" . $_POST["bd"] ."')";
    echo $q."<br>";
    if (!mysqli_query($con, $q)) {
      die('Error: ' . mysqli_error($con));
    }
    else {
      echo "Added!";
    }
  }
  if (isset($_POST["loginname"])) {
    $q="SELECT password, birthday FROM site_users WHERE name='" . $_POST["loginname"] . "'";
	echo "QUERY=$q<br>";
	$result = mysqli_query($con, $q);
	if (!$result) {
	  die('Error: ' . mysqli_error($con));
	}
	$row = mysqli_fetch_array($result);
	print_r($row);

	if (count($row) == 0) {
	    $show_text = "Unknown login!";
	}
	else {
		if ($row['password'] != sha1($_POST['loginpass'])) {
			$bad_pass = true;
		}
		else {
			$show_text = "Your birthday is ". $row['birthday'];
		}
	}
  }
  if (isset($_POST["chpname"])) {
	$q="UPDATE site_users SET password = '". $_POST["chppass"] . "' WHERE name='" . $_POST["chpname"] . "'";
	echo $q . "<br>";
	if (!mysqli_query($con, $q)) {
      die('Error: ' . mysqli_error($con));
    }
    else {
      echo "Updated!";
    }
  }
}
// x' or name != ''; -- 


mysqli_close($con);

// mysqli_real_escape_string

?>

<HTML>
<body>
<form action="index.php" method="post">
  Add Name: <input type="text" name="nm">
  Password: <input type="text" name="ps">
  Birthday: <input type="text" name="bd">
  <input type="submit">
<br><br>
</form>
<form action="index.php" method="post">
  Login: <input type="text" name="loginname">
  Password: <input type="text" name="loginpass">
  <input type="submit">
</form>
<br><br>
<form action="index.php" method="post">
  Change Password: Name: <input type="text" name="chpname">
  New Password: <input type="text" name="chppass">
  <input type="submit">
</form>
<?php
if ($bad_pass) {
	echo "<h1>BAD PASSWORD</h1>";
}
if ($show_text) {
	echo "<h3>$show_text</h3>";
}
?>

</body>
</HTML>