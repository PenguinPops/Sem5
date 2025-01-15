<?php
        header("Access-Control-Allow-Origin: *"); // Zezwala na dostęp z każdego źródła
        header("Access-Control-Allow-Methods: GET, POST, PUT, DELETE"); // Dozwolone metody
        header("Access-Control-Allow-Headers: Content-Type, Authorization"); // Dozwolone nagłówki

$tytul = "Informacje kontaktowe";
$zawartosc = "<h2>Katedra Informatyki</h2>";
$zawartosc .= "<h4>WEiI Politechnika Lubelska <br />";
$zawartosc .= "ul. Nadbystrzycka 36b, 20-618 Lublin<br />";
$zawartosc .= "tel. +48 815252046<br /></h4>";
$zawartosc .= "<h3>Laboratorium PAI - tworzenie modułowego serwisu WWW.
</h3>";

echo '<h1>'.$tytul.'</h1>', $zawartosc;