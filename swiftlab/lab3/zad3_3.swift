let imie = readLine()!
let drugieImie = readLine()!
let nazwisko = readLine()!
let rokUrodzenia = readLine()!

let nowyCiag = "Imię: \(imie)\nDrugie imię: \(drugieImie)\nNazwisko: \(nazwisko)\nRok urodzenia: \(rokUrodzenia)"
print(nowyCiag)

// usun drugie imie

let nowyCiagBezDrugiegoImienia = "Imię: \(imie)\nNazwisko: \(nazwisko)\nRok urodzenia: \(rokUrodzenia)"
print(nowyCiagBezDrugiegoImienia)

//usun rok urodzenia, dodaj wiek

let wiek = 2024 - Int(rokUrodzenia)!
let nowyCiagBezRokuUrodzenia = "Imię: \(imie)\nDrugie imię: \(drugieImie)\nNazwisko: \(nazwisko)\nWiek: \(wiek)"
print(nowyCiagBezRokuUrodzenia)

//sprawdz czy imie rozpoczyna sie litera 'D'

let zaczynaSieOdD = imie.first == "D"
if(zaczynaSieOdD) {
    print("Imię zaczyna się od litery 'D'")
} else {
    print("Imię nie zaczyna się od litery 'D'")
}


