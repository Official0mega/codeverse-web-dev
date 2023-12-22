<?php
session_start();

// Check if the username is set in the session.
if (isset($_SESSION["username"])) {
    $username = $_SESSION["username"];
} else {
    $username = "Unknown User or Username Not Found";
}
?>




<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Registration Successful</title>
    <link rel="stylesheet" href="./css/style.css">
</head>
<body>
    <div class=container>
        <h2>Registration Successful</h2>
        <p>Thank you for registering, <?php echo $username; ?>!</p>
    </div>
</body>
</html>