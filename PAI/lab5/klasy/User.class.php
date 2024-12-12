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

    public function __construct($username, $password, $fullName, $email, $created_at = null, $status = self::STATUS_USER)
    {
        $this->username = $username;
        $this->password = password_hash($password, PASSWORD_BCRYPT); 
        $this->fullName = $fullName;
        $this->email = $email;
        $this->created_at = $created_at ? new DateTime($created_at) : new DateTime();
        $this->status = $status;
    }

    public function show()
    {
        return $this->username . " " . $this->password . " " . $this->fullName . " " . $this->email . " " . $this->created_at->format('Y-m-d H:i:s') . " " . $this->status;
    }

    public function __get($name)
    {
        return $this->$name;
    }

    public function __set($name, $value)
    {
        $this->$name = $value;
    }

    static function getAllUsers($plik)
    {
        $tab = json_decode(file_get_contents($plik));
        foreach ($tab as $val) {
            echo "<p>" . $val->userName . " " . $val->fullName . " " . $val->date . "</p>";
        }
    }

    function toArray()
    {
        return [
            "userName" => $this->username,
            "fullName" => $this->fullName,
            "password" => $this->password,
            "email" => $this->email,
            "created_at" => $this->created_at->format('Y-m-d H:i:s'),
            "status" => $this->status
        ];
    }

    function save($plik)
    {
        $tab = json_decode(file_get_contents($plik), true) ?? [];
        array_push($tab, $this->toArray());
        file_put_contents($plik, json_encode($tab));
    }

    function saveXML($plik)
    {
        $xml = simplexml_load_file($plik);
        $xmlCopy = $xml->addChild("user");
        $xmlCopy->addChild("userName", $this->username);
        $xmlCopy->addChild("fullName", $this->fullName);
        $xmlCopy->addChild("password", $this->password);
        $xmlCopy->addChild("email", $this->email);
        $xmlCopy->addChild("created_at", $this->created_at->format('Y-m-d H:i:s'));
        $xmlCopy->addChild("status", $this->status);
        $xml->asXML($plik);
    }

    static function loadAllXML($plik)
    {
        $xml = simplexml_load_file($plik);
        foreach ($xml->user as $user) {
            echo "<p>" . $user->userName . " " . $user->fullName . " " . $user->created_at . "</p>";
        }
    }
}
