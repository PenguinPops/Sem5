<?php
include_once 'klasy/Baza.class.php';
include_once 'klasy/User.class.php';
include_once 'klasy/UserManager.class.php';

session_start(); // Rozpoczęcie sesji

$db = new Baza("localhost", "root", "", "klienci");
$um = new UserManager();

// Pobranie ID bieżącej sesji
$sessionId = session_id();

// Sprawdzenie, czy użytkownik jest zalogowany (czy istnieje w tabeli logged_in_users)
$sql = "SELECT userId FROM logged_in_users WHERE sessionId = '$sessionId'";
$result = $db->select($sql);

if (count($result) > 0) {
    // Użytkownik jest zalogowany - wyświetlenie jego danych
    $userId = $result[0]['userId'];

    // Pobranie danych użytkownika z tabeli users na podstawie $userId
    $userData = $db->select("SELECT * FROM users WHERE id = $userId");

    if (count($userData) > 0) {
        $user = $userData[0];
        echo "<h3>Dane zalogowanego użytkownika:</h3>";
        echo "ID: " . $user['id'] . "<br>";
        echo "Nazwa użytkownika: " . $user['userName'] . "<br>";
        echo "Email: " . $user['email'] . "<br>";
        echo "<a href='processLogin.php?akcja=wyloguj'>Wyloguj</a>";
    }
} else {
    // Brak sesji - przekierowanie do logowania
    header("Location: processLogin.php");
    exit();
}