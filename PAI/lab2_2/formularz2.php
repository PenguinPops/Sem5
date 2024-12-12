<!DOCTYPE html>
<html lang="pl">
<head>
 <meta charset="UTF-8">
 <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="CSS/style.css" type="text/css">
    <link rel="stylesheet" href="CSS/formularze.css" type="text/css">
    <title>Szybki kurs HTML - Formularz</title>
</head>
<body>
    <div id="baner"> <h2>Szybki kurs HTML</h2></div>
    <div id="menu">
        <a href="index.html">Podstawowe znaczniki</a>
        <a href="tabele.html">Tworzenie tabeli</a>
        <a href="formularze.html">Budowa formularzy</a>
    </div>
    
    <form method="POST" action="odbierz3.php">
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
                            <option value="p">Polska</option>
                            <option value="u">USA</option>
                            <option value="f">Francja</option>
                            <option value="r">Rosja</option>
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
            <input class="przycisk" type="radio" name="radio" value="eurocard">eurocard<br>
            <input class="przycisk" type="radio" name="radio" value="visa">visa<br>
            <input class="przycisk" type="radio" name="radio" value="przelew">przelew bankowy<br>

            <br>
            <input class="buton" type="submit" value="Wyślij">
            <input class="buton" type="reset" value="Anuluj">
        </div>
    </form>

    <div id="stopka"> &copy; MS </div>
</body>
</html>
