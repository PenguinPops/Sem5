<?php
$nazwa = 'obraz1';
echo "<h2>Galeria zdjęć</h2>";
//print("<img src='/../zdjecia/zdjecia/$nazwa.JPG' alt='$nazwa'>");

function galeria($rows, $cols) {
    print("<table border='1'>");
    for ($i = 0; $i < $rows; $i++) {
        print("<tr>");
        for ($j = 0; $j < $cols; $j++) {
            $nazwa = "obraz" . ($i * $cols + $j + 1);
            print("<td>");
            print("<img src='/../zdjecia/zdjecia/$nazwa.JPG' alt='$nazwa'>");
            print("</td>");
        }
        print("</tr>");
    }
    print("</table>");
}
galeria(3,3);
?>

