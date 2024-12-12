<?php
require_once("klasy/Strona.php");
$strona_akt = new Strona();
//dołącz plik z ustawioną zmienną $tytul i $zawartosc
$plik = "skrypty/main.php";
if (file_exists($plik)) {
    require_once($plik);
    $strona_akt->ustaw_tytul($tytul);
    $strona_akt->ustaw_zawartosc($zawartosc);
    $strona_akt->wyswietl();
}
echo "<script src='js/skrypty.js'></script>";