<?php
include_once "User.class.php";

class RegistrationForm {
    protected User $user;

    public function __construct() {
        echo "<h2>Formularz użytkownika</h2><br/>";
        echo '<form method="POST" action="index.php">';
        echo '<label for="username">Username:</label><br/>';
        echo '<input type="text" id="username" name="username"><br/><br/>';

        echo '<label for="password">Password:</label><br/>';
        echo '<input type="password" id="password" name="password"><br/><br/>';

        echo '<label for="name">Full Name:</label><br/>';
        echo '<input type="text" id="name" name="fullName"><br/><br/>';

        echo '<label for="email">Email:</label><br/>';
        echo '<input type="email" id="email" name="email"><br/><br/>';

        echo '<input type="submit" value="Submit" name="submit">';
        echo '</form>';
    }

    function checkUser($filename) {
        $args = [
            'username' => ['filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/[A-Za-z0-9]{4,25}$/']],
            'password' => ['filter' => FILTER_VALIDATE_REGEXP, 'options' => ['regexp' => '/^.*(?=.{3,})(?=.*[a-zA-Z])(?=.*\d)(?=.*[!#$%&? "]).*$/']],
            'fullName' => ['filter' => FILTER_VALIDATE_REGEXP, 'options'=> ['regexp' => '/[A-Za-ząęłńćżźó\w\s +]{2,40}$/']],
            'email' => FILTER_VALIDATE_EMAIL
        ];
        
        $dane = filter_input_array(INPUT_POST, $args);
        if (!$dane) {
            echo "<p>Błędne dane wejściowe.</p>";
            return null;
        }

        $errors = "";

        if ($this->isUsernameTaken($dane['username'], $filename)) {
            $errors .= "Błąd: Nazwa użytkownika jest już zajęta<br>";
        }

        foreach ($dane as $key => $value) {
            if ($value === false || $value === NULL) {
                $errors .= "Błąd w polu $key<br>";
            }
        }

        if ($errors === "") {
            // Create the user instance if data is valid
            $this->user = new User($dane['username'], $dane['password'], $dane['fullName'], $dane['email'], new DateTime(), User::STATUS_USER);
            $this->user->saveXML($filename); 
        } else {
            echo "<p>Błędne dane: $errors</p>";
            $this->user = null;
        }
        return $this->user;
    }
    
    private function isUsernameTaken($username, $filename) {
        $xml = simplexml_load_file($filename);
        foreach ($xml->user as $user) {
            if ((string) $user->userName === $username) {
                return true; 
            }
        }
        return false; 
    }
}