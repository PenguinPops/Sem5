<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);

session_start();
require 'klasy/User.class.php';

?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <title>Test 4 - Sesje</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            padding: 20px;
            background-color: #f4f4f4;
        }
        .container {
            background: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 2px 10px rgba(0,0,0,0.1);
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Test 4 - Sesje</h2>
        <p>ID sesji: <?php echo session_id(); ?></p>

        <h3>Właściwości obiektu User z sesji:</h3>
        <?php
        if (isset($_SESSION['user_data'])) {
            $user_data = unserialize($_SESSION['user_data']);

            if ($user_data) {
                ?>
                <ul>
                    <li>Nazwa użytkownika: <?php echo htmlspecialchars($user_data['username']); ?></li>
                    <li>Pełne imię i nazwisko: <?php echo htmlspecialchars($user_data['fullName']); ?></li>
                    <li>Email: <?php echo htmlspecialchars($user_data['email']); ?></li>
                    <li>Status: <?php echo $user_data['status'] == 1 ? 'Aktywny' : 'Nieaktywny'; ?></li>
                </ul>
                <?php
            } else {
                echo "<p>Obiekt User jest pusty.</p>";
            }
        } else {
            echo "<p>Brak informacji o użytkowniku w sesji.</p>";
        }
        ?>
    </div>
</body>
</html>
