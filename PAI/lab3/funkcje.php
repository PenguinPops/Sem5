<?php
    function dodaj()
    {
        // Pobieranie danych z formularza
        $nazwisko = $_POST['nazwisko'];
        $wiek = $_POST['wiek'];
        $panstwo = $_POST['panstwo'];
        $email = $_POST['email'];
        $jezyki = isset($_POST['jezyki']) ? implode(",", $_POST['jezyki']) : '';
        $sposob_zaplaty = $_POST['radio'];

        // Otwarcie pliku w trybie dopisywania
        $plik = fopen("dane.txt", "a");
        if ($plik) {
            // Tworzenie linii do zapisu w formacie: nazwisko wiek panstwo email jezyki sposob_zaplaty
            $wiersz = "$nazwisko $wiek $panstwo $email $jezyki $sposob_zaplaty\n";

            // Zapis do pliku
            fwrite($plik, $wiersz);
            fclose($plik);
            echo "Dane zostały zapisane.";
        } else {
            echo "Błąd przy otwieraniu pliku!";
        }
    }
    function pokaz()
    {
        if (file_exists("dane.txt")) {
            // Odczyt pliku
            $dane = file("dane.txt");

            echo "<h3>Wszystkie zamówienia:</h3>";
            echo "<ul>";
            foreach ($dane as $wiersz) {
                echo "<li>$wiersz</li>";
            }
            echo "</ul>";
        } else {
            echo "Plik nie istnieje!";
        }
    }
    function pokaz_zamowienie($jezyk) {
        if (file_exists("dane.txt")) {
            $dane = file("dane.txt");
    
            echo "<h3>Zamówienia na tutorial $jezyk:</h3>";
            echo "<ul>";
            foreach ($dane as $wiersz) {
                if (strpos($wiersz, $jezyk) !== false) {
                    echo "<li>$wiersz</li>";
                }
            }
            echo "</ul>";
        } else {
            echo "Plik nie istnieje!";
        }
    }