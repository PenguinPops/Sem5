<?php
class UserManager
{
    function loginForm()
    {
        ?>
        <h3>Formularz logowania</h3>
        <p>
        <form action="processLogin.php" method="post">
            <label for="login">Login:</label>
            <input type="text" name="login" required>
            <label for="passwd">Hasło:</label>
            <input type="password" name="passwd" required>
            <input type="submit" value="Zaloguj" name="zaloguj" />
        </form>
        </p>
        <?php
    }

    function login($db)
    {
        // sprawdza poprawność logowania
        $args = [
            'login' => FILTER_SANITIZE_ADD_SLASHES,
            'passwd' => FILTER_SANITIZE_ADD_SLASHES
        ];

        // Przefiltruj dane z POST zgodnie z ustawionymi filtrami w $args:
        $dane = filter_input_array(INPUT_POST, $args);
        $login = $dane["login"];
        $passwd = $dane["passwd"];

        // Sprawdź, czy użytkownik o podanym loginie istnieje i czy hasło jest poprawne
        $user = $db->selectUser($login, "users");

        if ($user) {
            $hashedPassword = $user['passwd'];
            // DEBUG
            // echo "DB: " . htmlspecialchars($hashedPassword) . "<br>";
            // echo "Password: " . htmlspecialchars(password_hash($passwd, PASSWORD_BCRYPT)) . "<br>";
            if (password_verify($passwd, $hashedPassword)) {
                // Poprawne dane logowania, wykonaj logowanie
                session_start();
                $data = date("Y-m-d H:i:s");
                $sessionId = session_id();
                $userId = $user['id']; 

                // Dodaj wpis do tabeli `logged_in_users` z informacjami o sesji
                $sql = "INSERT INTO logged_in_users (sessionId, userId, lastUpdate) VALUES ('$sessionId', '$userId', '$data')";
                $db->insert($sql);

                echo "<br>Użytkownik zalogowany<br>";
                return $userId;
            } else {
                // Niepoprawne hasło
                echo "<br>Niepoprawne hasło<br>";
                return -1;
            }
        } else {
            // Niepoprawny login
            echo "<br>Niepoprawny użytkownik";
            return -1;
        } 
    }

    function logout($db)
    {
        // Pobierz id bieżącej sesji
        session_start();
        $sessionId = session_id();

        // Usuń wpis z tabeli `logged_in_users` dla aktualnej sesji
        $sql = "DELETE FROM logged_in_users WHERE sessionId='$sessionId'";
        $db->delete($sql);

        // Usuń sesję (łącznie z ciasteczkiem sesyjnym)
        $_SESSION = [];
        if (ini_get("session.use_cookies")) {
            $params = session_get_cookie_params();
            setcookie(
                session_name(),
                '',
                time() - 42000,
                $params["path"],
                $params["domain"],
                $params["secure"],
                $params["httponly"]
            );
        }
        session_destroy();

        echo "<br>Użytkownik wylogowany<br>";
    }

    function getLoggedInUser($db, $sessionId)
    {
        // Funkcja sprawdza, czy istnieje wpis z danym `sessionId` w tabeli `logged_in_users`
        // Zwraca `user_id` użytkownika zalogowanego lub -1, jeśli nie ma wpisu dla danej sesji

        $sql = "SELECT user_id FROM logged_in_users WHERE session_id='$sessionId'";
        $result = $db->select($sql);

        if (!empty($result)) {
            // Jeśli wynik nie jest pusty, zwróć id użytkownika
            return $result[0]['user_id'];
        } else {
            // Jeśli wynik jest pusty, zwróć -1 (brak użytkownika)
            return -1;
        }
    }
}
