<?php
class User
{
    private $userName;
    private $fullName;
    private $email;
    private $passwd;
    private $status;
    private $date;

    public function __construct($userName, $fullName, $email, $passwd, $status)
    {
        $this->userName = $userName;
        $this->fullName = $fullName;
        $this->email = $email;
        $this->passwd = password_hash($passwd, PASSWORD_BCRYPT);
        $this->status = $status;
        $this->date = date('Y-m-d H:i:s');
    }

    public function saveDB($db)
    {
        $sql = "INSERT INTO users (userName, fullName, email, passwd, status, date) VALUES (?, ?, ?, ?, ?, ?)"; // ? - placeholder, który będzie zastąpiony wartością podaną w bind_param
        $stmt = $db->getMysqli()->prepare($sql); // przygotowanie zapytania
        $stmt->bind_param("ssssis", $this->userName, $this->fullName, $this->email, $this->passwd, $this->status, $this->date); // przypisanie wartości do placeholderów, ssssis oznacza typy danych, s to string, i to integer
        return $stmt->execute(); // wykonanie zapytania
    }

    public static function getAllUsersFromDB($db)
    {
        $sql = "SELECT * FROM users";
        $result = $db->select($sql, ['id', 'userName', 'fullName', 'email', 'status', 'date']);
        return $result;
    }
    public function getUserName()
    {
        return $this->userName;
    }

    public function getFullName()
    {
        return $this->fullName;
    }

    public function getEmail()
    {
        return $this->email;
    }

    public function getStatus()
    {
        return $this->status;
    }

    public function getDate()
    {
        return $this->date;
    }
}
