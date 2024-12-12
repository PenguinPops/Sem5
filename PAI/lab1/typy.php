<?php
$n1 = 1234;
$n2 = 567.789;
$n3 = 1;
$n4 = 0;
$n5 = true;
$n6 = "0";
$n7 = "Typy w PHP";
$n8 = [1, 2, 3, 4];
$n9 = [];
$n10 = ["zielony", "czerwony", "niebieski"];
$n11 = ["Agata", "Agatowska", 4.67, true];
$now = new DateTime();

echo "Current Date and Time: " . $now->format('Y-m-d H:i:s') . "<br>";

// Wyświetl nazwy i wartości poszczególnych zmiennych (dla tablic skorzystaj z funkcji
// count() do uzyskania liczby elementów tablicy)

echo "n1 = $n1, n2 = $n2, n3 = $n3, n4 = $n4, n5 = $n5, n6 = $n6, n7 = $n7<br>";
for($i = 0; $i < count($n8, COUNT_NORMAL); $i++) {
    echo "n8[$i] = $n8[$i]<br>";
}
for($i = 0; $i < count($n9, COUNT_NORMAL); $i++) {
    echo "n9[$i] = $n9[$i]<br>";
}
for($i = 0; $i < count($n10, COUNT_NORMAL); $i++) {
    echo "n10[$i] = $n10[$i]<br>";
}
for($i = 0; $i < count($n11, COUNT_NORMAL); $i++) {
    echo "n11[$i] = $n11[$i]<br>";
}

echo is_bool($n1)."<br>";
is_int($n2)."<br>";
is_numeric($n3)."<br>";
is_string($n4)."<br>";
is_array($n5)."<br>";
is_object($n6)."<br>";

printf("Wynik n3 == n5: %f<br>",  $n3 == $n5);
printf("Wynik n3 === n5: %f<br>",  $n3 === $n5);
printf("Wynik n4 == n6: %f<br>",  $n4 == $n6);
printf("Wynik n4 === n6: %f<br>",  $n4 === $n6);


var_dump($n10);
print_r($n11);

?>
