<!DOCTYPE html>
<html lang="pl">
<head>
 <meta charset="UTF-8">
 <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="CSS/style.css" type="text/css">
    <link rel="stylesheet" href="CSS/formularze.css" type="text/css">
    <title>Odbiór danych - Tutoriale</title>
</head>
<body>
    <div id="baner"> <h2>Odbiór danych z formularza</h2></div>

    <?php
    var_dump($_REQUEST);
    echo '<br>';
    if (isset($_REQUEST['jezyki']) && is_array($_REQUEST['jezyki'])) {
        echo "<h3>Zamówiłeś tutoriale z następujących języków:</h3>";
        
        // a) Wyświetlanie wybranych języków za pomocą pętli foreach
        echo "<ul>";
        foreach ($_REQUEST['jezyki'] as $jezyk) {
            echo "<li>" . htmlspecialchars($jezyk) . "</li>";
        }
        echo "</ul>";

        // b) Wyświetlanie wybranych języków jako listę połączoną funkcją join()
        $jezyki_lista = join(", ", $_REQUEST['jezyki']);
        echo "<p>Wybrałeś języki: " . htmlspecialchars($jezyki_lista) . "</p>";
    } else {
        echo "<p>Nie wybrano żadnych języków.</p>";
    }

    // Wyświetlenie pozostałych danych
    echo "<h3>Pozostałe dane:</h3>";
    echo "<p>Nazwisko: " . htmlspecialchars($_REQUEST['nazwisko']) . "</p>";
    echo "<p>Wiek: " . htmlspecialchars($_REQUEST['wiek']) . "</p>";
    echo "<p>Państwo: " . htmlspecialchars($_REQUEST['panstwo']) . "</p>";
    echo "<p>Adres e-mail: " . htmlspecialchars($_REQUEST['email']) . "</p>";

    // Sprawdzenie metody płatności
    if (isset($_REQUEST['radio'])) {
        echo "<p>Wybrany sposób zapłaty: " . htmlspecialchars($_REQUEST['radio']) . "</p>";
    } else {
        echo "<p>Nie wybrano sposobu zapłaty.</p>";
    }
    ?>
    
    <div id="stopka"> &copy; MS </div>
</body>
</html>
