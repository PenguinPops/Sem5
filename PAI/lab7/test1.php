<?php
session_start();

// Ustawienie zmiennych sesyjnych
$_SESSION['username'] = 'kubus';
$_SESSION['fullname'] = 'Kubus Puchatek';
$_SESSION['email'] = 'kubus@stumilowylas.pl';
$_SESSION['status'] = 'ADMIN';
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Test 1 - Sesje</title>
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
        <h2>Test 1 - Sesje</h2>
        <p>ID sesji: <?php echo session_id(); ?></p>
        
        <h3>Zmiennne sesyjne:</h3>
        <ul>
            <?php foreach ($_SESSION as $key => $value): ?>
                <li><?php echo htmlspecialchars($key) . ': ' . htmlspecialchars($value); ?></li>
            <?php endforeach; ?>
        </ul>

        <h3>Ciasteczka:</h3>
        <ul>
            <?php foreach ($_COOKIE as $key => $value): ?>
                <li><?php echo htmlspecialchars($key) . ': ' . htmlspecialchars($value); ?></li>
            <?php endforeach; ?>
        </ul>

        <a href="test2.php">Przejdź do Test 2</a>
    </div>
</body>
</html>
