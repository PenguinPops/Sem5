<?php
error_reporting(E_ALL);
ini_set('display_errors', 1);


include_once 'klasy/Baza.class.php';
include_once 'klasy/User.class.php';
include_once 'klasy/UserManager.class.php';
$db = new Baza("localhost", "root", "", "klienci");
$um = new UserManager();
//parametr z GET – akcja = wyloguj
if (filter_input(INPUT_GET, "akcja") == "wyloguj") {
    $um->logout($db);
}
//kliknięto przycisk submit z name = zaloguj
if (filter_input(INPUT_POST, "zaloguj")) {
    
    $userId = $um->login($db); //sprawdź parametry logowania
    if ($userId > 0) {
        echo "<p>Poprawne logowanie.<br />";
        echo "Zalogowany użytkownik o id=$userId <br />";
        echo "<a href='processLogin.php?akcja=wyloguj'>Wyloguj</a> </p>";
        header("location:testLogin.php");
    } else {
        echo "<p>Błędna nazwa użytkownika lub hasło</p>";
        //$um->loginForm(); //Pokaż formularz logowania
    }
} else {
    //pierwsze uruchomienie skryptu processLogin
    $um->loginForm();
}
// Tworzenie obiektu klasy Baza i próba połączenia
// try {
//     $db = new Baza('localhost', 'root', '', 'klienci');
//     echo "Połączenie z bazą danych powiodło się.";
// } catch (Exception $e) {
//     echo "Błąd połączenia z bazą danych: " . $e->getMessage();
// }