// Zadanie 10.5

class Osoba {
    private var imie: String;
    private var nazwisko: String;
    private var rokUrodzenia: Int;

    init(imie: String, nazwisko: String, rokUrodzenia: Int) {
        self.imie = imie;
        self.nazwisko = nazwisko;
        self.rokUrodzenia = rokUrodzenia;
    }

    func wiek() -> Int {
        return 2024 - rokUrodzenia;
    }

    func dane() -> String {
        return "\(imie) \(nazwisko) (\(rokUrodzenia))";
    }
}

var o1 = Osoba(imie:"Jan", nazwisko: "Kowalski", rokUrodzenia: 1990);
var o2 = Osoba(imie:"Anna", nazwisko: "Nowak", rokUrodzenia: 1985);

print("\(o1.dane()) - ma \(o1.wiek()) lat");
print("\(o2.dane()) - ma \(o2.wiek()) lat");

// Zadanie 10.6

class Pracownik : Osoba {
    private var rokZatrudnienia: Int;
    // Stanowisko powinno być z góry zdefiniowane jako typ wyliczeniowy.
    enum Stanowisko {
        case kierownik
        case kadry
        case pracownik
    }
    private var stanowisko: Stanowisko;
    private var stawka: Double;
    private var zrealizowaneGodziny: Int;
    private var nazwaFirmy: String;

    init(imie: String, nazwisko: String, rokUrodzenia: Int, rokZatrudnienia: Int, stanowisko: Stanowisko, stawka: Double, zrealizowaneGodziny: Int, nazwaFirmy: String) {
        // Inicjalizacja własnych właściwości klasy Pracownik
        self.rokZatrudnienia = rokZatrudnienia;
        self.stanowisko = stanowisko;
        self.stawka = stawka;
        self.zrealizowaneGodziny = zrealizowaneGodziny;
        self.nazwaFirmy = nazwaFirmy;

        // Wywołanie konstruktora klasy bazowej
        super.init(imie: imie, nazwisko: nazwisko, rokUrodzenia: rokUrodzenia);
    }


    func lataPracy() -> Int {
        return 2024 - rokZatrudnienia;
    }

    func pensjaWgGodzin() -> Double {
        return Double(zrealizowaneGodziny) * stawka;
    }

    override func dane() -> String {
        return "\(super.dane()) - \(stanowisko) w firmie \(nazwaFirmy). \nPracuje od \(rokZatrudnienia) roku, ma \(lataPracy()) lat doświadczenia. \nStawka godzinowa: \(stawka), zrealizowane godziny: \(zrealizowaneGodziny), pensja: \(pensjaWgGodzin())";
    }
}

var p1 = Pracownik(imie: "Jan", nazwisko: "Kowalski", rokUrodzenia: 1990, rokZatrudnienia: 2010, stanowisko: .kierownik, stawka: 50.0, zrealizowaneGodziny: 160, nazwaFirmy: "Firma 1");
var p2 = Pracownik(imie: "Anna", nazwisko: "Nowak", rokUrodzenia: 1985, rokZatrudnienia: 2015, stanowisko: .pracownik, stawka: 30.0, zrealizowaneGodziny: 180, nazwaFirmy: "Firma 2");

print(p1.dane());
print(p2.dane());

if(p1.wiek() < p2.wiek()) {
    print("Pracownik 1 jest młodszy");
}
else if (p1.wiek() > p2.wiek()){
    print("Pracownik 2 jest młodszy");
}
else {
    print("Są w tym samym wieku");
}