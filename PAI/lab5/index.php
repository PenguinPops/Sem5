<?php

include_once "klasy/User.class.php";
include_once "klasy/RegistrationForm.class.php";
$rf = new RegistrationForm();
if(filter_input(INPUT_POST, 'submit', FILTER_SANITIZE_FULL_SPECIAL_CHARS)) {
    $user = $rf->checkUser("users.xml");
    if($user === NULL)
        echo "<p>Niepoprawne dane rejestracji.</p>";
    else {
        echo "<p>Poprawne dane rejestracji: </p>";
        $user->show();
        // $user->save('users.json');
    }
}

// User::getAllUsers("users.json");
User::loadAllXML("users.xml");