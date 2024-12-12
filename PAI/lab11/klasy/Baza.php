<?php
class Baza
{
    private $mysqli;

    public function __construct($serwer, $user, $pass, $baza)
    {
        $this->mysqli = new mysqli($serwer, $user, $pass, $baza);

        if ($this->mysqli->connect_errno) {
            printf("Nie udało sie połączenie z serwerem: %s\n", $this->mysqli->connect_error);
            exit();
        }

        $this->mysqli->set_charset("utf8");
    }

    function __destruct()
    {
        $this->mysqli->close();
    }

    public function select($sql)
    {
        $wynik = []; // pusta tablica
        if ($result = $this->mysqli->query($sql)) { // jeśli zapytanie się udało
            while ($row = $result->fetch_assoc()) { // dopóki są wiersze do pobrania
                $wynik[] = $row; // dodaj wiersz do tablicy
            }
            $result->close(); // zamknij zapytanie
        }
        return $wynik;  // zwróć tablicę
    }

    public function selectHTML($sql, $pola)
    {
        $tresc = "<table><tbody>";
        $ilepol = count($pola);
        if ($result = $this->mysqli->query($sql)) {
            if ($result->num_rows > 0) {
                while ($row = $result->fetch_object()) {
                    $tresc .= "<tr>";
                    for ($i = 0; $i < $ilepol; $i++) {
                        $p = $pola[$i];
                        if (property_exists($row, $p)) {
                            $tresc .= "<td>" . htmlspecialchars($row->$p) . "</td>";
                        } else {
                            $tresc .= "<td>N/A</td>";
                        }
                    }
                    $tresc .= "</tr>";
                }
            } else {
                $tresc .= "<tr><td colspan='" . $ilepol . "'>No data found</td></tr>";
            }
            $result->close();
        } else {
            $tresc .= "<tr><td colspan='" . $ilepol . "'>Error executing query</td></tr>";
        }
        
        $tresc .= "</tbody></table>";
        return $tresc;
    }
    

    public function selectUser($login, $tabela)
    {
        // Query to fetch all usernames for debugging
        $sql = "SELECT userName FROM $tabela";
        $usernames = [];
        if ($result = $this->mysqli->query($sql)) {
            // Loop through the result to gather all usernames
            while ($row = $result->fetch_assoc()) {
                $usernames[] = $row['userName'];
            }
        }

        // Debug: List all usernames
        echo "All usernames in the table: <br>";
        foreach ($usernames as $username) {
            echo htmlspecialchars($username) . "<br>";  // Display each username safely
        }

        // Now query to fetch the user with the specific login
        $sql = "SELECT * FROM $tabela WHERE userName='$login'";

        if ($result = $this->mysqli->query($sql)) {
            $ile = $result->num_rows;
            if ($ile == 1) {
                // Fetch the user data
                $row = $result->fetch_assoc();  // Use fetch_assoc() to return an associative array
                // Debug: Show the retrieved user details
                echo "<br>Retrieved user: <br>";
                echo "Username: " . htmlspecialchars($row['userName']) . "<br>";
                echo "Full Name: " . htmlspecialchars($row['fullName']) . "<br>";
                echo "Email: " . htmlspecialchars($row['email']) . "<br>";
                return $row;  // Return the user data
            }
        }

        // If no user found, return null
        return null;  // Return null if user not found
    }




    public function delete($sql)
    {
        return $this->mysqli->query($sql) ? true : false;
    }

    public function insert($sql)
    {
        return $this->mysqli->query($sql) ? true : false;
    }

    public function getMysqli()
    {
        return $this->mysqli;
    }

    public function protect_string($str)
    {
        return $this->mysqli->real_escape_string($str);
    }

    public function protect_int($nmb)
    {
        return (int)$nmb;
    }
}
