<!DOCTYPE html>
<!-- index.php -->

<html>
    <head>
        <meta charset="UTF-8">
        <title>Lab 1</title>
    </head>
    <body>
        <?php
        echo "<h2>Pierwszy skrypt PHP</h2>";    
        $n = 5678;
        $x = 10.123456789;

        echo "Domyslny format: n=$n, x=$x<br>";
        printf("Zaokrąglenie do liczby całkowitej x=%.0f<br>", $x);
        printf("Zaokrąglenie do trzech miejsc po kropce x=%.2f<br>", $x);
        ?>
    </body>
</html>

