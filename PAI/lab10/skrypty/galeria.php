<?php
$tytul = "Galeria";
$zawartosc = '<div id="inside" style="display: flex; flex-wrap: wrap; gap: 10px; margin-left:10%; padding-right:50px; width: 80%;">';

foreach (range(1, 10) as $index => $obraz) {
    $zawartosc .= '<a href="zdjecia/obraz' . $obraz . '.JPG" style="flex: 1 1 calc(20% - 10px); text-align: center; margin-bottom: 10px;">
                    <img src="miniaturki/obraz' . $obraz . '.JPG" alt="obraz' . $obraz . '" style="width: 100%; height: auto;" />
                  </a>';
}

$zawartosc .= '</div>';