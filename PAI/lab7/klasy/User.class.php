<?php
class User
{
    const STATUS_USER = 1;
    const STATUS_ADMIN = 2;

    protected $id;
    protected $username;
    protected $password;
    protected $fullName;
    protected $email;
    protected DateTime $created_at;
    protected int $status;

    public function __construct($username, $fullName, $email, $password, $created_at = null, $status = self::STATUS_USER)
    {
        $this->username = $username;
        $this->password = password_hash($password, PASSWORD_BCRYPT);
        $this->fullName = $fullName;
        $this->email = $email;
        // instanceof sprawdza czy obiekt jest instancją klasy DateTime
        $this->created_at = $created_at instanceof DateTime ? $created_at : new DateTime();
        $this->status = $status;
    }

    public function saveDB($db)
    {
        // ? - placeholder
        $sql = "INSERT INTO users (userName, fullName, email, passwd, status, date) VALUES (?, ?, ?, ?, ?, ?)"; 
        $stmt = $db->getMysqli()->prepare($sql);
        $formattedCreatedAt = $this->created_at->format('Y-m-d H:i:s');
        // s - string, i - integer, bind_param - przypisanie wartości do placeholderów
        $stmt->bind_param("ssssis", $this->username, $this->fullName, $this->email, $this->password, $this->status, $formattedCreatedAt);
        return $stmt->execute();
    }

    public static function getAllUsersFromDB($db)
    {
        $sql = "SELECT * FROM users";
        $result = $db->select($sql, ['id', 'userName', 'fullName', 'email', 'status', 'date']);
        return $result;
    }
    public function getUserName()
    {
        return $this->username;
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
        return $this->created_at;
    }
}
