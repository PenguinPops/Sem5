// Zad 4

// Napisz program, który:

//     Tworzy strukturę do przechowywania informacji o samochodzie (marka, model, VIN, rok produkcji).
//     Przechowuje dane o samochodach w rejestrze (słowniku, gdzie kluczem jest numer rejestracyjny).
//     Umożliwia dodawanie nowego samochodu do rejestru poprzez dane wprowadzone przez użytkownika.
//     Umożliwia usunięcie samochodu z rejestru na podstawie numeru rejestracyjnego.
//     (Opcjonalnie) Pozwala na wyświetlenie numerów rejestracyjnych samochodów konkretnej marki.

struct Samochod {
    var marka: String;
    var model: String;
    var VIN: String;
    var rokProdukcji: Int;
}

var rejestr: [String: Samochod] = [:]

func dodajSamochod(_ marka: String, _ model: String, _ VIN: String, _ rokProdukcji: Int, _ numerRejestracyjny: String) {
    let samochod = Samochod(marka: marka, model: model, VIN: VIN, rokProdukcji: rokProdukcji);
    rejestr[numerRejestracyjny] = samochod;
}

func usunSamochod(_ numerRejestracyjny: String) {
    rejestr.removeValue(forKey: numerRejestracyjny);
}

func wyswietlSamochody(_ marka: String) {
    for (numerRejestracyjny, samochod) in rejestr {
        if samochod.marka == marka {
            print(rejestr[numerRejestracyjny]!);
        }
    }
}

dodajSamochod("Audi", "A4", "123456789", 2010, "KR12345");
dodajSamochod("Audi", "A6", "987654321", 2015, "KR54321");

wyswietlSamochody("Audi");

usunSamochod("KR12345");

wyswietlSamochody("Audi");


// Zadanie 5

// Pytanie:
// Napisz program, który:

//     Definiuje protokół Osoba z wymaganymi polami imie i nazwisko oraz funkcją wyswietlInfo.
//     Tworzy dwie klasy implementujące ten protokół:
//         Student z dodatkowymi polami (np. nrIndeksu),
//         Pracownik z dodatkowymi polami (np. rokZatrudnienia, pensja).
//     Pozwala na utworzenie obiektów tych klas i wyświetlenie ich informacji.

protocol Osoba {
    var imie: String { get set }
    var nazwisko: String { get set }

    func wyswietlInfo()
}

class Student : Osoba {
    var imie: String
    var nazwisko: String
    var nrIndeksu: Int

    init(imie: String, nazwisko: String, nrIndeksu: Int) {
        self.imie = imie
        self.nazwisko = nazwisko
        self.nrIndeksu = nrIndeksu
    }

    func wyswietlInfo() {
        print("Student: \(imie) \(nazwisko), nr indeksu: \(nrIndeksu)")
    }
}

class Pracownik : Osoba {
    var imie: String
    var nazwisko: String
    var rokZatrudnienia: Int
    var pensja: Double

    init(imie: String, nazwisko: String, rokZatrudnienia: Int, pensja: Double) {
        self.imie = imie
        self.nazwisko = nazwisko
        self.rokZatrudnienia = rokZatrudnienia
        self.pensja = pensja
    }

    func wyswietlInfo() {
        print("Pracownik: \(imie) \(nazwisko), zatrudniony w roku: \(rokZatrudnienia), pensja: \(pensja)")
    }
}

var student = Student(imie: "Jan", nazwisko: "Kowalski", nrIndeksu: 12345)

student.wyswietlInfo()

var pracownik = Pracownik(imie: "Adam", nazwisko: "Nowak", rokZatrudnienia: 2010, pensja: 5000)

pracownik.wyswietlInfo()