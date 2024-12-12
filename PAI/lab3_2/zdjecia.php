<?php
// Sprawdzenie, czy dane zostały przesłane
if (isset($_POST['zapisz']) && $_POST['zapisz'] == 'Zapisz' && !isset($_GET['pic'])) {
    // Sprawdzenie, czy plik został przesłany
    if (is_uploaded_file($_FILES['zdjecie']['tmp_name'])) {
        $typ = $_FILES['zdjecie']['type'];
        // Walidacja typu pliku
        if ($typ === 'image/jpeg') {
            // Zapisanie przesłanego zdjęcia
            $link = $_FILES['zdjecie']['name'];
            move_uploaded_file($_FILES['zdjecie']['tmp_name'], './' . $link);

            // Utworzenie kopii zdjęcia
            $random = uniqid('img_'); // Wygenerowanie losowej wartości
            $zdj = $random . '.jpg';
            copy('./' . $link, './' . $zdj); // Utworzenie kopii zdjęcia

            // Pobranie wymiarów zdjęcia
            list($width, $height) = getimagesize('./' . $zdj);
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

            // Utworzenie pliku graficznego
            header('Content-Type: image/jpeg');
            $nowe = imagecreatetruecolor($newW, $newH); // Czarny obraz
            $obraz = imagecreatefromjpeg('./' . $zdj);
            imagecopyresampled($nowe, $obraz, 0, 0, 0, 0, $newW, $newH, $width, $height);
            imagejpeg($nowe, './mini-' . $link, 100);
            echo "nowe=/mini-$link <br>";
            
            // Zwolnienie pamięci
            imagedestroy($nowe);
            imagedestroy($obraz);
            unlink('./' . $zdj); // Usunięcie kopii oryginalnego obrazu

            // Ustalanie linku do zdjęcia
            $dlugosc = strlen($link);
            $dlugosc -= 4; // Usunięcie rozszerzenia
            $link = substr($link, 0, $dlugosc);

            // Przekierowanie do miniatury
            header('location:zdjecia.php?pic=' . $link);
        } else {
            header('location:zdjecia.html'); // Nieprawidłowy typ pliku
        }
    }
}

// Sprawdzenie, czy został przesłany parametr pic
if (isset($_GET['pic']) && !empty($_GET['pic'])) {
    echo '<a href="' . $_GET['pic'] . '.JPG">Zdjęcie</a><br/>';
    echo '<a href="mini-' . $_GET['pic'] . '.JPG">Miniatura</a><br/><br/>';
    echo '<a href="zdjecia.html">Powrót</a>';
}
