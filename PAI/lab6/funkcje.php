<?php

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
function pokaz_zamowienie($jezyk)
{
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

function walidacja() {
    $args = [
        'nazwisko' => FILTER_SANITIZE_SPECIAL_CHARS,
        'wiek' => FILTER_VALIDATE_INT,
        'panstwo' => FILTER_SANITIZE_SPECIAL_CHARS,
        'email' => FILTER_VALIDATE_EMAIL,
        'jezyki' => ['filter' => FILTER_SANITIZE_SPECIAL_CHARS, 'flags' => FILTER_REQUIRE_ARRAY],
        'radio' => FILTER_SANITIZE_SPECIAL_CHARS,
    ];

    $dane = filter_input_array(INPUT_POST, $args);

    foreach ($dane as $key => $value) {
        if ($value === false || $value === NULL) {
            echo "Błąd w polu $key<br>";
        }
    }
    return $dane;
}


function dodaj()
{
    echo "<h3>Dodawanie do pliku</h3>";
    walidacja();
}

function dopliku($nazwaPliku, $tablicaDanych)
{
    $dane = "";
    //zbierz wartości z tablicy danych
    foreach ($tablicaDanych as $key => $value) {
        if (is_array($value)) {
            $dane .= implode(",", $value);
        } else {
            $dane .= $value;
        }
        $dane .= " ";
    }
    $dane .= PHP_EOL;
    //wykonaj operacje zapisu do pliku
    $plik = fopen("dane.txt", "a");
    if ($plik) {
        // Zapis do pliku
        fwrite($plik, $dane);
        fclose($plik);
        echo "Dane zostały zapisane.";
    } else {
        echo "Błąd przy otwieraniu pliku!";
    }

}

function statystyki()
{
    if (file_exists("dane.txt")) {
        $dane = file("dane.txt");
        $ilosc = count($dane);
        $mlodsi = 0;
        $starsi = 0;
        foreach ($dane as $wiersz) {
            $wiek = explode(" ", $wiersz)[4];
            if ($wiek < 18) {
                $mlodsi++;
            } else if ($wiek >= 50) {
                $starsi++;
            }
        }
        echo "<h3>Statystyki:</h3>";
        echo "<ul>";
        echo "<li>Ilość zamówień: $ilosc</li>";
        echo "<li>Liczba zamówień osób w wieku poniżej 18 lat: $mlodsi</li>";
        echo "<li>Liczba zamówień osób w wieku powyżej 50 lat: $starsi</li>";
        echo "</ul>";
    } else {
        echo "Plik nie istnieje!";
    }
}