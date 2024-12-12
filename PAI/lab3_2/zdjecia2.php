<?php
// Sprawdzenie, czy dane zostały przesłane
if (isset($_POST['zapisz']) && $_POST['zapisz'] == 'Zapisz' && !isset($_GET['pic'])) {
    // Sprawdzenie, czy plik został przesłany
    if (is_uploaded_file($_FILES['zdjecie']['tmp_name'])) {
        $typ = $_FILES['zdjecie']['type'];
        // Walidacja typu pliku
        if ($typ === 'image/jpeg') {
            // Tworzenie folderów, jeśli nie istnieją
            if (!is_dir('zdjecia')) {
                mkdir('zdjecia', 0777, true);
            }
            if (!is_dir('miniatury')) {
                mkdir('miniatury', 0777, true);
            }

            // Zapisanie przesłanego zdjęcia na serwerze
            $link = basename($_FILES['zdjecie']['name']);
            move_uploaded_file($_FILES['zdjecie']['tmp_name'], './zdjecia/' . $link);

            // Utworzenie kopii zdjęcia
            $random = uniqid('img_'); // Wygenerowanie losowej wartości
            $zdj = $random . '.jpg';
            copy('./zdjecia/' . $link, './zdjecia/' . $zdj); // Utworzenie kopii zdjęcia

            // Pobranie wymiarów zdjęcia
            list($width, $height) = getimagesize('./zdjecia/' . $zdj);
            $wys = $_POST['wys']; // Wysokość preferowana przez użytkownika
            $szer = $_POST['szer']; // Szerokość preferowana przez użytkownika
            
            $skalaWys = 1;
            $skalaSzer = 1;
            $skala = 1;

            // Obliczanie skali
            if ($width > $szer) $skalaSzer = $szer / $width;
            if ($height > $wys) $skalaWys = $wys / $height;
            if ($skalaWys <= $skalaSzer) $skala = $skalaWys;
            else $skala = $skalaSzer;

            // Ustalenie rozmiarów miniaturki
            $newH = $height * $skala;
            $newW = $width * $skala;

            // Utworzenie pliku graficznego (miniaturka)
            $nowe = imagecreatetruecolor($newW, $newH); // Czarny obraz
            $obraz = imagecreatefromjpeg('./zdjecia/' . $zdj);
            imagecopyresampled($nowe, $obraz, 0, 0, 0, 0, $newW, $newH, $width, $height);
            imagejpeg($nowe, './miniatury/mini-' . $link, 100);
            
            // Zwolnienie pamięci
            imagedestroy($nowe);
            imagedestroy($obraz);
            unlink('./zdjecia/' . $zdj); // Usunięcie kopii oryginalnego obrazu

            // Przekierowanie do galerii
            header('location:zdjecia2.php');
        } else {
            header('location:zdjecia.html'); // Nieprawidłowy typ pliku
        }
    }
}

// Wyświetlanie miniatur wszystkich zdjęć
if ($handle = opendir('./miniatury')) {
    echo '<h2>Galeria</h2>';
    while (false !== ($entry = readdir($handle))) { // readdir() zwraca nazwę pliku, while zwraca false, gdy nie ma już plików
        if ($entry != "." && $entry != "..") {
            // Wyświetlanie miniaturki jako hiperłącza do pełnego zdjęcia
            $originalImage = './zdjecia/' . str_replace('mini-', '', $entry);
            $thumbnail = './miniatury/' . $entry;
            echo '<a href="' . $originalImage . '"><img src="' . $thumbnail . '" alt="' . $entry . '" style="margin:10px;"/></a>';
        }
    }
    closedir($handle);
}

echo '<br/><br/><a href="zdjecia.html">Powrót</a>';