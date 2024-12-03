var osoba1 = (imie: "Jan", nazwisko: "Pawlas", rokUr: 1999)

var osoba2 = (imie: "Anna", nazwisko: "Pawluk", rokUr: 1999)

if osoba1.rokUr > osoba2.rokUr {
    print("Ta osoba jest starsza: \(osoba2.imie) \(osoba2.nazwisko)")
} else if osoba1.rokUr < osoba2.rokUr {
    print("Ta osoba jest starsza: \(osoba1.imie) \(osoba1.nazwisko)")
} else {
    print("Obie osoby są w tym samym wieku")
}

// Zadanie 3

print("Wprowadź liczbę mieszkań: ", terminator: "")

guard let x = Int(readLine()!) else { fatalError("🐶") }
var tablicaMieszkan: [(lokalizacja: String, powierzchnia: Double, cena_za_metr: Double)] = []
var najwiecej: Double = 0
var najmniej: Double = 0
var maxIndex = 0
var minIndex = 0
for y in 0..<x {
    print("Wprowadź lokalizacje mieszkania \(y): ", terminator: "")
    guard let lok: String = readLine() else { fatalError("🐶") }
    print("Wprowadź powierzchnie mieszkania \(y): ", terminator: "")
    guard let pow: Double = Double(readLine()!) else { fatalError("🐶") }
    print("Wprowadź cene za metr mieszkania \(y): ", terminator: "")
    guard let cena: Double = Double(readLine()!) else { fatalError("🐶") }
    if y == 0 {
        najwiecej = cena * pow
        najmniej = cena * pow
    } else {
        if cena * pow > najwiecej {
            najwiecej = cena * pow
            maxIndex = y
        }
        if cena * pow < najmniej {
            najmniej = cena * pow
            minIndex = y
        }
    }
    tablicaMieszkan.append((lokalizacja: lok, powierzchnia: pow, cena_za_metr: cena))
}
print(
    "Najtansze mieszkanie: [\(tablicaMieszkan[minIndex].lokalizacja), \(tablicaMieszkan[minIndex].powierzchnia), \(tablicaMieszkan[minIndex].cena_za_metr)]"
)
print(
    "Najdrozsze mieszkanie: [\(tablicaMieszkan[maxIndex].lokalizacja), \(tablicaMieszkan[maxIndex].powierzchnia), \(tablicaMieszkan[maxIndex].cena_za_metr)]"
)

// Zadanie 4

enum Miesiac {
    case styczen
    case luty
    case marzec
    case kwiecien
    case maj
    case czerwiec
    case lipiec
    case sierpien
    case wrzesien
    case pazdziernik
    case listopad
    case grudzien
}

var poraRoku: Miesiac = .styczen
switch(poraRoku) {
    case .styczen, .luty, .grudzien:
        print("Zima")
    case .marzec, .kwiecien, .maj:
        print("Wiosna")
    case .czerwiec, .lipiec, .sierpien:
        print("Lato")
    case .wrzesien, .pazdziernik, .listopad:
        print("Jesień")
}

// Zadanie 5

enum Standard {
    case wysoki
    case średni
    case niski
}
var nowaTablicaMieszkan: [(lokalizacja: String, powierzchnia: Double, cena_za_metr: Double, standard: Standard)] = [];

for y in 0..<tablicaMieszkan.count {
    if(tablicaMieszkan[y].cena_za_metr * tablicaMieszkan[y].powierzchnia < 200000) {
        nowaTablicaMieszkan.append((lokalizacja: tablicaMieszkan[y].lokalizacja, powierzchnia: tablicaMieszkan[y].powierzchnia, cena_za_metr: tablicaMieszkan[y].cena_za_metr, standard: .niski))
    }
    else if((tablicaMieszkan[y].cena_za_metr * tablicaMieszkan[y].powierzchnia >= 200000) && (tablicaMieszkan[y].cena_za_metr * tablicaMieszkan[y].powierzchnia < 400000)) {
        nowaTablicaMieszkan.append((lokalizacja: tablicaMieszkan[y].lokalizacja, powierzchnia: tablicaMieszkan[y].powierzchnia, cena_za_metr: tablicaMieszkan[y].cena_za_metr, standard: .średni))
    }
    else {
        nowaTablicaMieszkan.append((lokalizacja: tablicaMieszkan[y].lokalizacja, powierzchnia: tablicaMieszkan[y].powierzchnia, cena_za_metr: tablicaMieszkan[y].cena_za_metr, standard: .wysoki))
    }
    print("Mieszkanie \(y): \(nowaTablicaMieszkan[y].lokalizacja), \(nowaTablicaMieszkan[y].powierzchnia), \(nowaTablicaMieszkan[y].cena_za_metr), \(nowaTablicaMieszkan[y].standard)")
}
