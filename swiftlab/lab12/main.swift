import Foundation

// Zad 12.1 ------------------------

// Utwórz protokół LiczbaZepolona, która zawiera dwie właściwości: re (część
// rzeczywistą liczby) oraz im (część urojoną liczby).

protocol LiczbaZepolona {
    var re: Double { get }
    var im: Double { get }
}

// Utwórz klasę OperacjeNaLiczbachZespolonych, która zaimplementuje
// dodawanie dwóch liczb, odejmowanie dwóch liczb oraz wyświetlanie liczby zespolonej.
// Klasa musi adoptować zdefiniowany protokół.

class OperacjeNaLiczbachZespolonych: LiczbaZepolona {
    var re: Double
    var im: Double
    
    init(re: Double, im: Double) {
        self.re = re
        self.im = im
    }
// :) :) :)
    func dodaj(_ liczba: LiczbaZepolona) -> LiczbaZepolona {
        return OperacjeNaLiczbachZespolonych(re: re + liczba.re, im: im + liczba.im)
    }
    
    func odejmij(_ liczba: LiczbaZepolona) -> LiczbaZepolona {
        return OperacjeNaLiczbachZespolonych(re: re - liczba.re, im: im - liczba.im)
    }
    
    func wyswietl() {
        print("Liczba zespolona: \(re) + \(im)i")
    }
}

// Zad 12.2 ------------------------

// Utwórz protokół LiczbaLosowa, która zawiera funkcję generujLiczbę()
// zwracającą losową liczbę typu całkowitego.

protocol LiczbaLosowa {
    func generujLiczbe() -> Int
}

// Utwórz klasę Liczby, która adoptuje zdefiniowany protokół, zawierającą 2 liczby
// całkowite. Klasa powinna zawierać takie funkcje jak: wyświetlenie 2 liczb oraz podniesienie
// liczby do potęgi zdefiniowanej jako parametr.

class Liczby: LiczbaLosowa {
    var liczba1: Int
    var liczba2: Int
    
    init(liczba1: Int, liczba2: Int) {
        self.liczba1 = liczba1
        self.liczba2 = liczba2
    }
    
    func generujLiczbe() -> Int {
        return Int.random(in: 0...100)
    }
    
    func wyswietl() {
        print("Liczba 1: \(liczba1), Liczba 2: \(liczba2)")
    }
    
    func potega(_ liczba: Int, _ potega: Int) -> Int {
        return Int(pow(Double(liczba), Double(potega)))
    }
}

// Zad 12.3 ------------------------

// Zdefiniuj typ wyliczeniowy do obsługi błędów dotyczących: dzielenia przez 0
// oraz obliczenie pierwiastka z liczby niedodatniej.

enum Bledy: Error {
    case dzieleniePrzezZero
    case pierwiastekZLiczbyNiedodatniej
}

// Utwórz funkcję, która wywoła odpowiednie błędy

func obliczenia(_ a: Double, _ b: Double) throws -> Double {
    if b == 0 {
        throw Bledy.dzieleniePrzezZero
    }
    if a < 0 {
        throw Bledy.pierwiastekZLiczbyNiedodatniej
    }
    return a / b
}

// Obsłuż błędy za pomocą instrukcji do-catch.

do {
    let wynik = try obliczenia(4, 2)
    print("Wynik dzielenia: \(wynik)")
} catch Bledy.dzieleniePrzezZero {
    print("Dzielenie przez 0")
} catch Bledy.pierwiastekZLiczbyNiedodatniej {
    print("Pierwiastek z liczby niedodatniej")
}

// Utwórz program składający wykonujący operację dzielenia dwóch liczb
// całkowitych oraz pierwiastkowania.

func dzielenieIPierwiastkowanie(_ a: Double, _ b: Double) {
    do {
        let wynik = try obliczenia(a, b)
        print("Wynik: \(wynik)")
    } catch Bledy.dzieleniePrzezZero {
        print("Dzielenie przez zero")
    } catch Bledy.pierwiastekZLiczbyNiedodatniej {
        print("Pierwiastek z liczby niedodatniej")
    } catch {
        print("Nieznany błąd")
    }
}

// Przykład użycia:
dzielenieIPierwiastkowanie(9, 3)
dzielenieIPierwiastkowanie(-4, 2)
dzielenieIPierwiastkowanie(10, 0)

// Zad 12.4 ------------------------

// Zdefiniuj typ wyliczeniowy do obsługi błędów podczas wypłacania pieniędzy z
// bankomatu: niewystarczające środki na koncie, brak kwoty w bankomacie, przekroczenie
// kwoty dziennego limitu, brak możliwości wypłacenia kwoty (brak nominałów), inny błąd (np.
// błędna kwota).

enum BledyBankomat: Error {
    case niewystarczajaceSrodki
    case brakKwoty
    case przekroczenieLimitu
    case brakMozliwosciWyplacenia
    case innyBlad
}

// Utwórz funkcję, która wywoła odpowiednie błędy.

func wyplacPieniadze(_ kwota: Int, _ limit: Int) throws {
    if kwota > limit {
        throw BledyBankomat.przekroczenieLimitu
    }
    if kwota % 10 != 0 {
        throw BledyBankomat.innyBlad
    }
}

// Obsłuż błędy za pomocą instrukcji do-catch

do {
    try wyplacPieniadze(100, 50)
} catch BledyBankomat.przekroczenieLimitu {
    print("Przekroczenie limitu")
} catch BledyBankomat.innyBlad {
    print("Inny błąd")
}

// Utwórz program, który wczyta od użytkownika kwotę do wypłaty w bankomacie
// oraz wyświetli informacje o poprawnie wykonanej operacji lub o błędzie, który wystąpił.
// Kwota w bankomacie oraz nominały można zdefiniować w programie jako stałe.

func bankomat(_ kwota: Int) {
    let limit = 1000
    let dostepnaKwota = 5000 // Definiujemy dostępne środki w bankomacie
    
    do {
        if kwota > dostepnaKwota {
            throw BledyBankomat.brakKwoty
        }
        try wyplacPieniadze(kwota, limit)
        print("Pieniądze zostały wypłacone: \(kwota) zł")
    } catch BledyBankomat.przekroczenieLimitu {
        print("Przekroczenie dziennego limitu wypłaty")
    } catch BledyBankomat.brakKwoty {
        print("Brak wystarczających środków w bankomacie")
    } catch BledyBankomat.innyBlad {
        print("Niepoprawna kwota do wypłaty")
    } catch {
        print("Nieznany błąd")
    }
}

// Przykład użycia:
bankomat(150)
bankomat(1050)
bankomat(6000)
