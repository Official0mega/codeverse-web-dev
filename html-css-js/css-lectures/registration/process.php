<?php
session_start();
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST["username"];
    $email = $_POST["email"];

    // Perfrom any necessary validation and database operations here

    $_SESSION["username"] = $username;

    // Redirect the user to the success page
    header("Location: success.php");
    exit();
}
?>