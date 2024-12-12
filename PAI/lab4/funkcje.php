<?php
function pokaz($wiersz) {
    $czesci = explode(";", trim($wiersz));

    if (count($czesci) === 5) {
        list($nazwisko, $kraj, $jezyki, $email, $wiek) = $czesci;

        $jezyki = trim($jezyki, "[]");
        $jezykiList = explode(",", $jezyki);

        echo "<li><strong>Nazwisko:</strong> $nazwisko, ";
        echo "<strong>Kraj:</strong> $kraj, ";
        echo "<strong>Języki:</strong> " . implode(", ", array_map('trim', $jezykiList)).", ";
        echo "<strong>Adres e-mail:</strong> $email, ";
        echo "<strong>Wiek:</strong> $wiek</li>";
    } else {
        echo "<li>Błąd w formacie wiersza: $wiersz</li>";
    }
}

function pokaz_wszystkie() {
    if (file_exists("dane.txt")) {
        $dane = file("dane.txt");

        echo "<h3>Wszystkie zamówienia:</h3>";
        echo "<ul>";

        foreach ($dane as $wiersz) {
            pokaz($wiersz);
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
            $czesci = explode(";", trim($wiersz)); // usuwamy białe znaki z początku i końca wiersza

            if (count($czesci) === 5) {                                // sprawdzamy czy wiersz ma 5 części
                list($nazwisko, $kraj, $jezykiStr, $email, $wiek) = $czesci;  // przypisujemy części do zmiennych

                $jezykiStr = trim($jezykiStr, "[]");      // usuwamy nawiasy kwadratowe z listy języków
                $jezyki = array_map('trim', explode(",", $jezykiStr)); // dzielimy listę języków na tablicę i usuwamy białe znaki

                if (in_array($jezyk, $jezyki)) {
                    pokaz($wiersz);
                }
            }
        }
        echo "</ul>";
    } else {
        echo "Plik nie istnieje!";
    }
}

    
    
    
    
    
    
    function walidacja() {
        $args = ['nazw' => ['filter' => FILTER_VALIDATE_REGEXP, 'options' =>['regexp' => '/^[A-Z]{1}[a-ząęłńćżźó-]{1,25}$/']
        ],
        'kraj' => FILTER_SANITIZE_FULL_SPECIAL_CHARS,
        'jezyki' => ['filter' => FILTER_SANITIZE_FULL_SPECIAL_CHARS, 'flags' => FILTER_REQUIRE_ARRAY],
        'email' => FILTER_VALIDATE_EMAIL,
        'wiek' => ['filter' => FILTER_VALIDATE_INT, 'options' => ['min_range' => 1, 'max_range' => 120]],
        ];

        $dane = filter_input_array(INPUT_POST, $args);
        var_dump($dane);

        $errors = "";
        foreach($dane as $key => $value) {
            if($value === false || $value === NULL) {
                $errors .= "Błąd w polu $key<br>";
            }
        }

        if($errors === "") {
            dopliku("dane.txt", $dane);
        } else {
            echo $errors;
        }
    }

    function dodaj() {
        echo "<h3>Dodawanie do pliku</h3>";
        walidacja();
    }

    function dopliku($nazwaPliku, $tablicaDanych) {
        $nazwisko = $tablicaDanych['nazw'] ?? '';
        $kraj = $tablicaDanych['kraj'] ?? '';
        $email = $tablicaDanych['email'] ?? '';
        $wiek = $tablicaDanych['wiek'] ?? '';
    
        $jezyki = isset($tablicaDanych['jezyki']) ? '[' . implode(",", $tablicaDanych['jezyki']) . ']' : '[]';
    
        $wiersz = "$nazwisko;$kraj;$jezyki;$email;$wiek" . PHP_EOL;

        $plik = fopen($nazwaPliku, "a");
        if ($plik) {
            fwrite($plik, $wiersz);
            fclose($plik);
            echo "Dane zostały zapisane.";
        } else {
            echo "Błąd przy otwieraniu pliku!";
        }
    }
    

    function statystyki() {
        if (file_exists("dane.txt")) {
            $dane = file("dane.txt");
            $ilosc = count($dane);
            $mlodsi = 0;
            $starsi = 0;
    
            foreach ($dane as $wiersz) {
                $czesci = explode(";", trim($wiersz));
    
                if (count($czesci) === 5) {
                    list($nazwisko, $kraj, $jezyki, $email, $wiek) = $czesci;
    
                    $wiek = (int)$wiek;
                    if ($wiek < 18) {
                        $mlodsi++;
                    } else if ($wiek >= 50) {
                        $starsi++;
                    }
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
    