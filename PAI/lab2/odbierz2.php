<body>
    <h2>Dane przesłane metodą GET:</h2> <!-- Nagłówek sekcji wyświetlającej dane przesłane metodą GET. -->
    <?php
    // Sprawdzenie, czy są dane przesłane metodą GET (czy $_GET nie jest puste)
    if (!empty($_GET)) { 
        var_dump($_GET); 
        // Funkcja 'var_dump' wyświetla szczegółowe informacje o tablicy $_GET (wartości, typy danych itp.).
        echo "<br />"; // Przerwa w linii dla przejrzystości wyświetlania danych.
        
        // Iteracja po wszystkich kluczach i wartościach w tablicy $_GET
        foreach ($_GET as $key => $value) {
            if (is_array($value)) {
                foreach ($value as $subValue) {
                    echo htmlspecialchars("$key = $subValue") . "<br />";
                }
            } else {
                echo htmlspecialchars("$key = $value") . "<br />";
            }
        }
        
    } else {
        // Jeśli nie ma danych przesłanych metodą GET, wyświetlany jest komunikat
        echo "Brak danych przesłanych metodą GET.<br />";
    }
    ?>

    <h2>Dane przesłane metodą POST:</h2> <!-- Nagłówek sekcji wyświetlającej dane przesłane metodą POST. -->
    <?php
    // Sprawdzenie, czy są dane przesłane metodą POST (czy $_POST nie jest puste)
    if (!empty($_POST)) { 
        var_dump($_POST); 
        // 'var_dump' wyświetla szczegółowe informacje o tablicy $_POST.
        echo "<br />"; // Przerwa w linii.
        
        // Iteracja po wszystkich kluczach i wartościach w tablicy $_POST
        foreach ($_GET as $key => $value) {
            if (is_array($value)) {
                foreach ($value as $subValue) {
                    echo htmlspecialchars("$key = $subValue") . "<br />";
                }
            } else {
                echo htmlspecialchars("$key = $value") . "<br />";
            }
        }
    } else {
        // Jeśli nie ma danych przesłanych metodą POST, wyświetlany jest komunikat
        echo "Brak danych przesłanych metodą POST.<br />";
    }
    ?>

    <h2>Wszystkie dane z $_REQUEST:</h2> <!-- Nagłówek sekcji wyświetlającej wszystkie dane z $_REQUEST (łączy dane GET i POST). -->
    <?php
    // Sprawdzenie, czy są dane przesłane metodą GET lub POST (czy $_REQUEST nie jest puste)
    if (!empty($_REQUEST)) { 
        var_dump($_REQUEST); 
        // 'var_dump' wyświetla szczegółowe informacje o tablicy $_REQUEST, która zawiera dane zarówno z GET, jak i POST.
        echo "<br />"; // Przerwa w linii.
        
        // Iteracja po wszystkich kluczach i wartościach w tablicy $_REQUEST
        foreach ($_GET as $key => $value) {
            if (is_array($value)) {
                foreach ($value as $subValue) {
                    echo htmlspecialchars("$key = $subValue") . "<br />";
                }
            } else {
                echo htmlspecialchars("$key = $value") . "<br />";
            }
        }
    } else {
        // Jeśli nie ma żadnych danych w $_REQUEST, wyświetlany jest komunikat
        echo "Brak danych w $_REQUEST.<br />";
    }
    ?>
</body>
