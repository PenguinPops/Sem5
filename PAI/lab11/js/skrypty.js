document.addEventListener('DOMContentLoaded', () => {
    console.log("Skrypt załadowany pomyślnie!");
    pokazOnas();

    var bonas = document.getElementById('onas');
    bonas.addEventListener("click", () => {
        console.log("Strona O nas");
        pokazOnas();
    });

    var bgaleria = document.getElementById('galeria');
    bgaleria.addEventListener("click", () => {
        console.log("Galeria zdjęć");
        pokazGalerie();
    });

    var bglowna = document.getElementById('index');
    bglowna.addEventListener("click", () => {
        console.log("Strona główna");
        pokazGlowna();
    });

    var bformularz = document.getElementById('formularz');
    bformularz.addEventListener("click", () => {
        console.log("Formularz");
        pokazFormularz();
    });
});

// Funkcja do ładowania strony "O nas"
function pokazOnas() {
    fetch("http://localhost/PAI/lab11/skrypty/onas.php")
        .then((response) => {
            if (response.status !== 200) {
                return Promise.reject('Coś poszło nie tak!');
            }
            return response.text();
        })
        .then((data) => {
            document.getElementById('main').innerHTML = data;
        })
        .catch((error) => {
            console.log(error);
        });
}

// Funkcja do ładowania galerii
function pokazGalerie() {
    fetch("http://localhost/PAI/lab11/skrypty/galeria.php")
        .then((response) => {
            if (response.status !== 200) {
                return Promise.reject('Coś poszło nie tak!');
            }
            return response.text();
        })
        .then((data) => {
            document.getElementById('main').innerHTML = data;
        })
        .catch((error) => {
            console.log(error);
        });
}

// Funkcja do ładowania formularza
function pokazFormularz() {
    fetch("http://localhost/PAI/lab11/skrypty/formularz.php")
        .then((response) => {
            if (response.status !== 200) {
                return Promise.reject('Coś poszło nie tak!');
            }
            return response.text();
        })
        .then((data) => {
            document.getElementById('main').innerHTML = data;
            // Dodajemy obsługę formularza (jeśli jest)
            dodajFormularzEventListener();
        })
        .catch((error) => {
            console.log(error);
        });
}

// Funkcja do ładowania strony głównej
function pokazGlowna() {
    fetch("http://localhost/PAI/lab11/skrypty/glowna.php")
        .then((response) => {
            if (response.status !== 200) {
                return Promise.reject('Coś poszło nie tak!');
            }
            return response.text();
        })
        .then((data) => {
            document.getElementById('main').innerHTML = data;
        })
        .catch((error) => {
            console.log(error);
        });
}

// Funkcja do obsługi formularza
function dodajFormularzEventListener() {
    const form = document.getElementById('form');
    if (form) {
        console.log("Formularz znaleziony, dodawanie zdarzeń dla przycisków...");
        // Obsługa przycisku Dodaj
        const btnDodaj = document.getElementById('btnDodaj');
        btnDodaj.addEventListener('click', () => {
            const formData = new FormData(form);
            formData.append('submit', 'Dodaj');

            fetch("http://localhost/PAI/lab11/skrypty/formularz.php", {
                method: "POST",
                body: formData
            })
                .then((response) => {
                    if (response.status !== 200) {
                        return Promise.reject('Coś poszło nie tak przy wysyłaniu danych!');
                    }
                    return response.text();
                })
                .then((result) => {
                    console.log("Dane dodane pomyślnie. Odpowiedź: ", result);
                    document.getElementById('main').innerHTML = result;
                })
                .catch((error) => {
                    console.error(error);
                });
        });

        // Obsługa przycisku Pokaż
        const btnPokaz = document.getElementById('btnPokaz');
        btnPokaz.addEventListener('click', () => {
            const formData = new FormData(form);
            formData.append('submit', 'Pokaż');

            fetch("http://localhost/PAI/lab11/skrypty/formularz.php", {
                method: "POST",
                body: formData
            })
                .then((response) => {
                    if (response.status !== 200) {
                        return Promise.reject('Coś poszło nie tak przy wysyłaniu danych!');
                    }
                    return response.text();
                })
                .then((result) => {
                    console.log("Dane wyświetlone pomyślnie. Odpowiedź: ", result);
                    document.getElementById('main').innerHTML = result;
                })
                .catch((error) => {
                    console.error(error);
                });
        });
    } else {
        console.error("Formularz nie został znaleziony!");
    }
}
