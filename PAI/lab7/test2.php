<?php
session_start();
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Test 2 - Sesje</title>
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
        <h2>Test 2 - Sesje</h2>
        <p>ID sesji przed usunięciem: <?php echo session_id(); ?></p>

        <h3>Zmiennne sesyjne:</h3>
        <ul>
            <?php foreach ($_SESSION as $key => $value): ?>
                <li><?php echo htmlspecialchars($key) . ': ' . htmlspecialchars($value); ?></li>
            <?php endforeach; ?>
        </ul>

        <h3>Usuwanie sesji...</h3>
        <?php
        // Usunięcie zmiennych sesyjnych
        $_SESSION = []; // Zresetowanie zmiennych sesyjnych

        // Usunięcie ciasteczka sesyjnego
        if (ini_get("session.use_cookies")) { // Sprawdzenie, czy sesje używają ciasteczek
            $params = session_get_cookie_params(); // Pobranie parametrów ciasteczka sesyjnego
            setcookie(session_name(), '', time() - 42000, // Ustawienie czasu ważności ciasteczka na 1 stycznia 1970
                $params["path"], $params["domain"], // Ustawienie ścieżki i domeny
                $params["secure"], $params["httponly"] // Ustawienie flag bezpieczeństwa
            );
        }

        // Zniszczenie sesji
        session_destroy();

        // Rozpoczęcie nowej sesji, aby uzyskać nowy identyfikator sesji
        session_start();
        ?>

        <p>ID sesji po usunięciu: <?php echo session_id(); ?></p>
        <p>Sesja została usunięta. <a href="test1.php">Powrót do Test 1</a></p>
    </div>
</body>
</html>
