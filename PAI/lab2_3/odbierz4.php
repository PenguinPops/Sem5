<!DOCTYPE html>
<html lang="pl">
<head>
 <meta charset="UTF-8">
 <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="CSS/style.css" type="text/css">
    <link rel="stylesheet" href="CSS/formularze.css" type="text/css">
    <title>Odbiór zamówienia</title>
</head>
<body>
    <div id="baner"> <h2>Odbiór zamówienia</h2></div>

    <?php
    // Wyświetlanie zamówionych języków
    if (isset($_REQUEST['jezyki']) && is_array($_REQUEST['jezyki'])) {
        echo "<h3>Zamówiłeś tutoriale z następujących języków:</h3>";
        echo "<ul>";
        foreach ($_REQUEST['jezyki'] as $jezyk) {
            echo "<li>" . htmlspecialchars($jezyk) . "</li>";
        }
        echo "</ul>";
    } else {
        echo "<p>Nie wybrano żadnych języków.</p>";
    }

    // Wyświetlanie sposobu zapłaty
    if (isset($_REQUEST['radio'])) {
        echo "<p>Wybrany sposób zapłaty: " . htmlspecialchars($_REQUEST['radio']) . "</p>";
    } else {
        echo "<p>Nie wybrano sposobu zapłaty.</p>";
    }

    // Sprawdzenie danych klienta i generowanie linku lub komunikatu
    if (isset($_REQUEST['nazwisko']) && !empty($_REQUEST['nazwisko']) &&
        isset($_REQUEST['wiek']) && !empty($_REQUEST['wiek']) &&
        isset($_REQUEST['panstwo']) && !empty($_REQUEST['panstwo']) &&
        isset($_REQUEST['email']) && !empty($_REQUEST['email'])) {
        
        // Tworzenie linku do strony klient.php
        echo '<p><a href="klient.php?nazwisko=' . urlencode($_REQUEST['nazwisko']) .
             '&wiek=' . urlencode($_REQUEST['wiek']) .
             '&panstwo=' . urlencode($_REQUEST['panstwo']) .
             '&email=' . urlencode($_REQUEST['email']) . '">Zobacz dane zamawiającego</a></p>';
    } else {
        // Brak danych klienta
        echo "<p>Brak pełnych danych klienta.</p>";
    }
    ?>

    <p><a href="formularz3.php">powrót do formularza</a></p>

    <div id="stopka"> &copy; MS </div>
</body>
</html>
