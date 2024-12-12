<h2>Wybierz technologie, które znasz:</h2>
<form method="GET" action="ankieta.php">
<?php
$jezyki = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];
foreach ($jezyki as $jezyk) {
    echo '<input class="przycisk" type="checkbox" name="jezyki[]" value="' . $jezyk . '">' . $jezyk . '<br>';
}
?>
<a href="ankieta.php"><input class="button" type="submit" value="Zapisz" name="submit"></a>
</form>

<?php
if (isset($_GET['jezyki']) && is_array($_GET['jezyki'])) {
    $langlist = $_GET['jezyki']; // Pobieramy wybrane języki przez użytkownika
    $filePath = "ankieta.txt";

    // Inicjalizujemy tablicę na zawartość pliku
    $zawartosc = [];

    // Wczytujemy istniejące dane z pliku, jeśli plik istnieje
    if (file_exists($filePath)) {
        $plik = fopen($filePath, "r+");
        if ($plik) {
            while (($linia = fgets($plik)) !== false) {
                list($klucz, $wartosc) = explode(": ", trim($linia));
                $zawartosc[$klucz] = (int)$wartosc;
            }
            fclose($plik);
        }
    }

    // Aktualizujemy licznik tylko dla wybranych języków
    foreach ($langlist as $jezyk) {
        if (isset($zawartosc[$jezyk])) {
            $zawartosc[$jezyk]++;
        } else {
            $zawartosc[$jezyk] = 1;
        }
    }

    // Zapisujemy zaktualizowane dane do pliku
    $plik = fopen($filePath, "w"); // Otwarcie w trybie zapisu, co wyczyści plik
    if ($plik) {
        foreach ($zawartosc as $klucz => $wartosc) {
            fwrite($plik, $klucz . ": " . $wartosc . "\n");
        }
        fclose($plik);
    } else {
        echo "Błąd przy otwieraniu pliku!";
    }
}
?>
