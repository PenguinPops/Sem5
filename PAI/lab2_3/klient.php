<!DOCTYPE html>
<html lang="pl">
<head>
 <meta charset="UTF-8">
 <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="CSS/style.css" type="text/css">
    <link rel="stylesheet" href="CSS/formularze.css" type="text/css">
    <title>Dane zamawiającego</title>
</head>
<body>
    <div id="baner"> <h2>Dane zamawiającego</h2></div>

    <?php
    // Sprawdzanie, czy wszystkie dane są przekazane w URL-u
    if (isset($_GET['nazwisko']) && !empty($_GET['nazwisko']) &&
        isset($_GET['wiek']) && !empty($_GET['wiek']) &&
        isset($_GET['panstwo']) && !empty($_GET['panstwo']) &&
        isset($_GET['email']) && !empty($_GET['email'])) {

        // Wyświetlanie danych zamawiającego
        echo "<p><strong>Nazwisko:</strong> " . htmlspecialchars($_GET['nazwisko']) . "</p>";
        echo "<p><strong>Wiek:</strong> " . htmlspecialchars($_GET['wiek']) . "</p>";
        echo "<p><strong>Państwo:</strong> " . htmlspecialchars($_GET['panstwo']) . "</p>";
        echo "<p><strong>Adres e-mail:</strong> " . htmlspecialchars($_GET['email']) . "</p>";
    } else {
        // Komunikat, jeśli brakuje danych
        echo "<p>Brak pełnych danych zamawiającego.</p>";
    }
    ?>

    <div id="stopka"> &copy; MS </div>
</body>
</html>
