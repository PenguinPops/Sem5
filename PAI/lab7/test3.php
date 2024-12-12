<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

session_start();
require 'klasy/User.class.php'; 


if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    
    $userName = $_POST['userName'];
    $fullName = $_POST['fullName'];
    $email = $_POST['email'];
    $passwd = $_POST['passwd'];
    $status = 1; 

    
    $user = new User($userName, $passwd, $fullName, $email, new DateTime(), $status);

    
    $_SESSION['user_data'] = serialize([$user]);

    
    echo '<pre>';
    print_r($_SESSION['user_data']); // ROZPAKUJ TO bo po danych 
    
    echo '</pre>';

    
    header('Location: test4.php');
    exit();
}
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <title>Test 1 - Rejestracja</title>
</head>
<body>
    <h2>Rejestracja Użytkownika</h2>
    <form method="POST">
        <label for="userName">Nazwa użytkownika:</label>
        <input type="text" name="userName" id="userName" required>

        <label for="fullName">Pełne imię i nazwisko:</label>
        <input type="text" name="fullName" id="fullName" required>

        <label for="email">Email:</label>
        <input type="email" name="email" id="email" required>

        <label for="passwd">Hasło:</label>
        <input type="password" name="passwd" id="passwd" required>

        <button type="submit">Zarejestruj</button>
    </form>
</body>
</html>
