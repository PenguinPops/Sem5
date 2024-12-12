<?php
function drukuj_form()
{
    $zawartosc = '<div id="tresc">
    <form action="?strona=formularz" method="POST" style="margin-left:20%;">
        <table style="width: 60%;"> 
            <tr>
                <td>Nazwisko</td>
                <td><input type="text" name="nazwisko" style="width: 100%;"></td>
            </tr>
            <tr>
                <td>Wiek</td>
                <td><input type="number" name="wiek" style="width: 100%;"></td>
            </tr>
            <tr>
                <td>Państwo</td>
                <td>
                    <select name="panstwo" style="width: 100%;">
                        <option value="Polska">Polska</option>
                        <option value="Niemcy">Niemcy</option>
                        <option value="Wielka Brytania">Wielka Brytania</option>
                        <option value="Czechy">Czechy</option>
                    </select>
                </td>
            </tr>
            <tr>
                <td>Adres e-mail (wymagane)</td>
                <td><input type="email" name="email" style="width: 100%;"></td>
            </tr>
            </table>
            <h2 style="margin-right:23%;">Zamawiam tutorial z języka:</h2>
            <table style="width: 60%;">
                <tr>
                    <td colspan="2">';
            $jezyki = ["C", "CPP", "Java", "C#", "HTML", "CSS", "XML", "PHP", "JavaScript"];
            foreach ($jezyki as $jezyk) {
                $zawartosc .= '<input class="przycisk" type="checkbox" name="jezyki[]" value="' . $jezyk . '">' . $jezyk;
            }
            
            $zawartosc.='</td>
            </tr>
            </table>
            <h2 style="margin-right:23%;">Sposób zapłaty:</h2>
            <table style="width: 60%;">
            <tr>
                <td colspan="2">
                    <input type="radio" name="radio" value="Master Card"> Master Card
                    <input type="radio" name="radio" value="Visa"> Visa
                    <input type="radio" name="radio" value="Przelew"> Przelew bankowy
                </td>
            </tr>
            <tr>
                <td colspan="2" style="text-align: center; padding-top: 10px;">
                    <button type="submit" name="submit" value="Dodaj" style="margin-right: 5px;">Dodaj</button>
                    <button type="submit" name="submit" value="Pokaż" style="margin-right: 5px;">Pokaż</button>
                    <button type="reset">Anuluj</button>
                </td>
            </tr>
        </table>
    </form>
</div>';

    return $zawartosc;
}
function walidacja() {
    $args = [
        'nazwisko' => FILTER_SANITIZE_SPECIAL_CHARS,
        'wiek' => FILTER_VALIDATE_INT,
        'panstwo' => FILTER_SANITIZE_SPECIAL_CHARS,
        'email' => FILTER_VALIDATE_EMAIL,
        'jezyki' => ['filter' => FILTER_SANITIZE_SPECIAL_CHARS, 'flags' => FILTER_REQUIRE_ARRAY],
        'radio' => FILTER_SANITIZE_SPECIAL_CHARS,
    ];

    $dane = filter_input_array(INPUT_POST, $args);

    foreach ($dane as $key => $value) {
        if ($value === false || $value === NULL) {
            echo "Błąd w polu $key<br>";
        }
    }
    return $dane;
}
function dodajdoBD($bd)
{ 
    $dane = walidacja();
    $nazwisko = $dane['nazwisko'] ?? '';
    $wiek = $dane['wiek'] ?? '';
    $panstwo = $dane['panstwo'] ?? '';
    $email = $dane['email'] ?? '';
    $jezyki = isset($dane['jezyki']) ? implode(",", $dane['jezyki']) : ''; 
    $radio = $dane['radio'] ?? '';
    $columns = ["Nazwisko", "Wiek", "Panstwo", "Email", "Zamowienie", "Platnosc"];
    $values = [$nazwisko, $wiek, $panstwo, $email, $jezyki, $radio];
    $query = "INSERT INTO klienci (" . implode(", ", $columns) . ") VALUES ('" . implode("', '", $values) . "')";

    $bd->insert($query);
    return "Dodano do bazy danych!";
}
//uchwyt do bazy klienci:
include_once "klasy/Baza.php";
$tytul = "Formularz zamowienia";
$zawartosc = drukuj_form();
$bd = new Baza("localhost", "root", "", "klienci");
if (filter_input(INPUT_POST, "submit")) {
    $akcja = filter_input(INPUT_POST, "submit");
    switch ($akcja) {
        case "Dodaj":
            $zawartosc .= dodajdoBD($bd);
            break;
        case "Pokaż":
            $zawartosc .= "<h2>Wszystkie zamówienia:</h2><br/>";
            $zawartosc .= '<div style="display:flex;justify-content:center";">'.$bd->selectHTML(
                "select * from klienci",
                ["Email", "Zamowienie"]
            ).'</div>';
            break;
    }
}
