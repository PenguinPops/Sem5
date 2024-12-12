<form action="css.php" method="post">
<textarea name="tekst"></textarea><br />
<input type="submit" name="wyslij" value="Wyślij" />
</form>
<div>
<?php
if (filter_input(INPUT_POST, 'wyslij')) {
    $tekst = filter_input(INPUT_POST, 'tekst');
    echo htmlspecialchars($tekst) . "<br>";
    echo strip_tags($tekst) . "<br>";
    echo filter_var($tekst, FILTER_SANITIZE_STRING) . "<br>";
    echo filter_var($tekst, FILTER_SANITIZE_SPECIAL_CHARS) . "<br>";
}
?>
</div>