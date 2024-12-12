<form method="POST" action="index.php">
    <h3>Przykładowy formularz HTML</h3>
    <div>
        <table>
            <tr>
                <td><label for="naz">Nazwisko: </label></td>
                <td><input id="naz" type="text" name="nazwisko"></td>
            </tr>
            <tr>
                <td><label for="wiek">Wiek: </label></td>
                <td><input id="wiek" type="text" name="wiek"></td>
            </tr>
            <tr>
                <td>Państwo:</td>
                <td>
                    <select name="panstwo" class="przycisk">
                        <option value="Polska">Polska</option>
                        <option value="Niemcy">Niemcy</option>
                        <option value="Wielka Brytania">Wielka Brytania</option>
                        <option value="Czechy">Czechy</option>
                    </select>
                </td>
            </tr>
            <tr>
                <td><label for="mail">Adres e-mail: </label></td>
                <td><input id="mail" type="email" name="email" maxlength="30" size="30"></td>
            </tr>
        </table>

        <h4>Zamawiam tutorial z języka:</h4>
        <?php
        $jezyki = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];
        foreach ($jezyki as $jezyk) {
            echo '<input class="przycisk" type="checkbox" name="jezyki[]" value="' . $jezyk . '">' . $jezyk . '<br>';
        }
        ?>

        <h4>Sposób zapłaty:</h4>
        <input class="przycisk" type="radio" name="radio" value="Master Card">Master Card<br>
        <input class="przycisk" type="radio" name="radio" value="visa">Visa<br>
        <input class="przycisk" type="radio" name="radio" value="Przelew">Przelew bankowy<br>

        <br>
        <input class="button" type="reset" value="Wyczyść" name="submit">
        <input class="button" type="submit" value="Zapisz" name="submit">
        <input class="button" type="submit" value="Pokaż" name="submit">
        <input class="button" type="submit" value="PHP" name="submit">
        <input class="button" type="submit" value="CPP" name="submit">
        <input class="button" type="submit" value="Java" name="submit">
    </div>
</form>

<?php
include_once("funkcje.php");
include_once "klasy/Baza.class.php";

$bd = new Baza("localhost", "root", "", "klienci");

if (filter_input(INPUT_POST, "submit")) {
    $akcja = filter_input(INPUT_POST, "submit");

    switch ($akcja) {
        case "Zapisz":
            dodajdoBD($bd);
            break;
        case "Pokaż":
            echo $bd->select("SELECT Nazwisko, Zamowienie FROM klienci", ["Nazwisko", "Zamowienie"]);
            break;
        case "PHP":
            pokaz_zamowienie("PHP");
            break;
        case "CPP":
            pokaz_zamowienie("CPP");
            break;
        case "Java":
            pokaz_zamowienie("Java");
            break;
    }
}

function dodajdoBD($bd)
{
    $nazwisko = filter_input(INPUT_POST, "nazwisko", FILTER_SANITIZE_SPECIAL_CHARS);
    $wiek = filter_input(INPUT_POST, "wiek", FILTER_SANITIZE_NUMBER_INT);
    $panstwo = filter_input(INPUT_POST, "panstwo", FILTER_SANITIZE_SPECIAL_CHARS);
    $email = filter_input(INPUT_POST, "email", FILTER_SANITIZE_EMAIL);
    $jezyki = filter_input(INPUT_POST, "jezyki", FILTER_DEFAULT, FILTER_REQUIRE_ARRAY);
    $sposob_zaplaty = filter_input(INPUT_POST, "radio", FILTER_SANITIZE_SPECIAL_CHARS);

    if ($nazwisko && $wiek && $panstwo && $email && !empty($jezyki) && $sposob_zaplaty) {

        $jezyki_str = implode(",", $jezyki); 

        $sql = "INSERT INTO klienci (Nazwisko, Wiek, Panstwo, Email, Zamowienie, Platnosc) 
                VALUES ('$nazwisko', '$wiek', '$panstwo', '$email', 
                '$jezyki_str', '$sposob_zaplaty')";

        //echo "SQL: $sql<br>";

        if ($bd->insert($sql)) {
            echo "Dane zostały zapisane pomyślnie.";
        } else {
            echo "Błąd podczas zapisu danych do bazy danych: " . $bd->getMysqli()->error;
        }
    } else {
        echo "Nie wszystkie dane zostały wprowadzone poprawnie.";
    }
}
?>
