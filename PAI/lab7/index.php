<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

session_start();
require 'klasy/Baza.class.php';
require 'klasy/User.class.php';

// Połączenie z bazą danych
$db = new Baza('localhost', 'root', '', 'klienci');

// Rejestracja użytkownika
if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $userName = $_POST['userName'];
    $fullName = $_POST['fullName'];
    $email = $_POST['email'];
    $passwd = $_POST['passwd'];
    $status = 1;

    $user = new User($userName, $fullName, $email, $passwd, new DateTime(), $status);
    $user->saveDB($db);
}

// Pobranie wszystkich użytkowników
$users = User::getAllUsersFromDB($db);
// echo "<br>$users<br>";
?>

<!DOCTYPE html>
<html lang="pl">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Rejestracja Użytkownika</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f9;
            color: #333;
            display: flex;
            flex-direction: column;
            align-items: center;
            padding: 20px;
        }

        .container {
            max-width: 600px;
            width: 100%;
            padding: 20px;
            background: #fff;
            border-radius: 8px;
            box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
        }

        h2 {
            color: #333;
        }

        form {
            display: flex;
            flex-direction: column;
        }

        label,
        input,
        button {
            margin-bottom: 10px;
        }

        input,
        button {
            padding: 10px;
            border-radius: 4px;
            border: 1px solid #ddd;
            font-size: 16px;
        }

        button {
            background-color: #5a67d8;
            color: #fff;
            cursor: pointer;
            transition: background-color 0.3s;
        }

        button:hover {
            background-color: #4c51bf;
        }

        .user-list {
            margin-top: 20px;
        }

        .user-list table {
            width: 100%;
            border-collapse: collapse;
        }

        .user-list th,
        .user-list td {
            padding: 8px;
            border: 1px solid #ddd;
            text-align: left;
        }

        .user-list th {
            background-color: #f1f1f1;
        }
    </style>
</head>

<body>
    <div class="container">
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

        <div class="user-list">
            <h2>Lista Użytkowników</h2>
            <table>
                <tr>
                    <th>ID</th>
                    <th>Nazwa użytkownika</th>
                    <th>Pełne imię</th>
                    <th>Email</th>
                    <th>Status</th>
                    <th>Data rejestracji</th>
                </tr>
                <?php
                if ($users):
                    // print_r($users);
                    foreach ($users as $user):
                        echo "<tr>";
                        echo "<td>" . htmlspecialchars($user['id']) . "</td>";
                        echo "<td>" . htmlspecialchars($user['userName']) . "</td>";
                        echo "<td>" . htmlspecialchars($user['fullName']) . "</td>";
                        echo "<td>" . htmlspecialchars($user['email']) . "</td>";
                        echo "<td>" . ($user['status'] == 1 ? 'Użytkownik' : 'Administrator') . "</td>";
                        echo "<td>" . htmlspecialchars($user['date']) . "</td>";
                        echo "</tr>";
                    endforeach;
                else:
                    echo "<tr><td colspan='6'>Brak zarejestrowanych użytkowników.</td></tr>";
                endif;
                ?>

            </table>
        </div>
    </div>
</body>

</html>