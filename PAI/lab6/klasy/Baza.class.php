<?php
class Baza { // popraw java
    private $mysqli;

    public function __construct($serwer, $user, $pass, $baza) {
        $this->mysqli = new mysqli($serwer, $user, $pass, $baza);

        if ($this->mysqli->connect_errno) {
            printf("Nie udało sie połączenie z serwerem: %s\n", $this->mysqli->connect_error);
            exit();
        }

        $this->mysqli->set_charset("utf8");
    }

    function __destruct() {
        $this->mysqli->close();
    }

    public function select($sql, $pola) {
        $tresc = "";
        if ($result = $this->mysqli->query($sql)) {
            $ilepol = count($pola);
            $tresc .= "<table><tbody>";
            // fetch_object - zwraca obiekt z właściwościami odpowiadającymi nazwom kolumn
            while ($row = $result->fetch_object()) {
                $tresc .= "<tr>";
                for ($i = 0; $i < $ilepol; $i++) {
                    $p = $pola[$i];
                    $tresc .= "<td>" . $row->$p . "</td>";
                }
                $tresc .= "</tr>";
            }
            $tresc .= "</table></tbody>";
            $result->close();
        }
        return $tresc;
    }

    // po polach, statystyki, zrobić SELECTEM z bazy od razu

    public function delete($sql) {
        return $this->mysqli->query($sql) ? true : false;
    }

    public function insert($sql) {
        return $this->mysqli->query($sql) ? true : false;
    }

    public function getMysqli() {
        return $this->mysqli;
    }
}
