<body>
    <div>
        <h2>Dane odebrane z formularza:</h2> <!-- Nagłówek wyświetlany na stronie, informujący o odebranych danych z formularza. -->
        
        <?php
        // Sprawdzenie, czy nazwisko zostało przesłane i nie jest puste
        if (isset($_REQUEST['nazw']) && ($_REQUEST['nazw'] != "")) { 
            // Funkcja 'isset' sprawdza, czy zmienna 'nazw' jest ustawiona.
            // Dodatkowo warunek sprawdza, czy nie jest pusta (różna od pustego stringa).
            
            $nazwisko = htmlspecialchars(trim($_REQUEST['nazw'])); 
            // 'trim' usuwa białe znaki (spacje) z początku i końca łańcucha.
            // 'htmlspecialchars' zabezpiecza przed wprowadzeniem kodu HTML lub JavaScript (ochrona przed atakami XSS).
            echo "Nazwisko: $nazwisko <br />"; // Wyświetlenie przesłanego nazwiska.
        } else {
            echo "Nie wpisano nazwiska <br />"; // Komunikat w przypadku, gdy pole "nazwisko" było puste lub nie zostało przesłane.
        }

        // Sprawdzenie, czy wiek został przesłany
        if (isset($_REQUEST['wiek']) && ($_REQUEST['wiek'] != "")) {
            $wiek = htmlspecialchars(trim($_REQUEST['wiek'])); 
            // Analogiczne jak w przypadku nazwiska: usunięcie białych znaków i zabezpieczenie danych.
            echo "Wiek: $wiek <br />"; // Wyświetlenie przesłanego wieku.
        } else {
            echo "Nie wpisano wieku <br />"; // Komunikat w przypadku, gdy pole "wiek" było puste lub nie zostało przesłane.
        }

        // Sprawdzenie, czy państwo zostało przesłane
        if (isset($_REQUEST['panstwo']) && ($_REQUEST['panstwo'] != "")) {
            $panstwo = htmlspecialchars(trim($_REQUEST['panstwo'])); 
            // Analogiczne jak w poprzednich przypadkach: czyszczenie i zabezpieczenie danych.
            echo "Państwo: $panstwo <br />"; // Wyświetlenie przesłanego państwa.
        } else {
            echo "Nie wpisano państwa <br />"; // Komunikat, gdy pole "państwo" było puste lub nie zostało przesłane.
        }

        // Sprawdzenie, czy email został przesłany
        if (isset($_REQUEST['email']) && ($_REQUEST['email'] != "")) {
            $email = htmlspecialchars(trim($_REQUEST['email']));
            // Usuwanie białych znaków i zabezpieczenie adresu e-mail.
            echo "Email: $email <br />"; // Wyświetlenie przesłanego adresu e-mail.
        } else {
            echo "Nie wpisano adresu email <br />"; // Komunikat, gdy pole "email" było puste lub nie zostało przesłane.
        }

        // Sprawdzenie, czy zostały wybrane jakiekolwiek tutoriale z tablicy jezyki

        if (isset($_REQUEST['jezyki']) && !empty($_REQUEST['jezyki'])) {
            $jezyki = $_REQUEST['jezyki']; // Przypisanie tablicy z wybranymi językami do zmiennej.
            echo "Wybrane tutoriale: <br />"; // Wyświetlenie komunikatu o wybranych tutorialach.
            foreach ($jezyki as $jezyk) { // Iteracja po tablicy z wybranymi językami.
                echo htmlspecialchars($jezyk) . "<br />"; // Wyświetlenie wybranego języka.
            }
        } else {
            echo "Nie wybrano żadnych tutoriali <br />"; // Komunikat, gdy nie wybrano żadnych tutoriali.
        }


        // Sprawdzenie, czy metoda płatności została przesłana
        if (isset($_REQUEST['platnosc']) && ($_REQUEST['platnosc'] != "")) {
            $platnosc = htmlspecialchars(trim($_REQUEST['platnosc']));
            // Usunięcie białych znaków i zabezpieczenie danych dotyczących metody płatności.
            echo "Sposób zapłaty: $platnosc <br />"; // Wyświetlenie przesłanej metody płatności.
        } else {
            echo "Nie wybrano metody płatności <br />"; // Komunikat, gdy nie wybrano żadnej metody płatności.
        }
        ?>

        <a href="formularz.html">Powrót do formularza</a> <!-- Link do powrotu na stronę z formularzem. -->
    </div>
</body>