// Zadanie 11.1

class Prostokat {
    var a: Double;
    var b: Double;

    init(a: Double, b: Double) {
        self.a = a;
        self.b = b;
    }

    func pole() -> Double {
        return a*b;
    }

    func obwod() -> Double {
        return 2*a + 2*b;
    }

    func dane() -> String {
        return "Prostokąt, Pole: \(pole()), Obwód: \(obwod())";
    }
}

// Zadanie 11.2

class Prostopadloscian : Prostokat {
    private var h: Double;

    init(a: Double, b: Double, h: Double) {
        self.h = h;
        super.init(a: a, b: b);
    }

    override func pole() -> Double {
        return (a*b+a*h+b*h)*2;
    }

    func sumaKrawedzi() -> Double {
        return (a+b+h)*4;
    }

    func objetosc() -> Double {
        return a*b*h;
    }

    override func dane() -> String {
        return "Prostopadłościan, Pole: \(pole()), Objętość: \(objetosc()), Suma Krawędzi: \(sumaKrawedzi())";
    }
}

// Zadanie 11.3

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

class Student: Osoba {
    var nrIndeksu: Int;
    enum Kierunek {
        case Informatyka;
        case Mechatronika;
        case Architektura;
        case Budownictwo;
    }
    var kierunek: Kierunek;
    var rokStudiow: Int;
    // oceny z 5 przedmiotów jako klucz: wartość
    var oceny: [String: Double]

    init(imie: String, nazwisko: String, rokUrodzenia: Int, nrIndeksu: Int, kierunek: Kierunek, rokStudiow: Int, oceny: [String: Double]) {
        // Sprawdzamy, czy oceny mieszczą się w dozwolonym zakresie
        for ocena in oceny.values {
            if ocena < 2.0 || ocena > 5.0 {
                fatalError("Ocena \(ocena) jest niepoprawna. Oceny muszą być w zakresie od 2.0 do 5.0.")
            }
        }

        // Inicjalizujemy właściwości
        self.nrIndeksu = nrIndeksu
        self.kierunek = kierunek
        self.rokStudiow = rokStudiow
        self.oceny = oceny

        // Wywołujemy konstruktor klasy bazowej
        super.init(imie: imie, nazwisko: nazwisko, rokUrodzenia: rokUrodzenia)
    }

    func srednia() -> Double {
        guard !oceny.isEmpty else { return 0.0 }
        return oceny.values.reduce(0, +) / Double(oceny.count)
    }

    override func dane() -> String {
        return "\(super.dane()), \(nrIndeksu), \(kierunek), \(rokStudiow), Średnia: \(srednia())"
    }
}

// Utworz tablice studentów, liczbę ich należy pobrać od użytkownika, a potem wczytać ich dane, używając guard, zrób to w funkcji wczytaj()

func wczytaj() -> [Student] {
    print("Podaj liczbę studentów:")
    guard let liczbaStudentow = Int(readLine()!) else {
        fatalError("Podana wartość nie jest liczbą całkowitą.")
    }

    var studenci: [Student] = []
    
    for _ in 0..<liczbaStudentow {
        print("Podaj imię:")
        guard let imie = readLine() else {
            fatalError("Imię nie może być puste.")
        }

        print("Podaj nazwisko:")
        guard let nazwisko = readLine() else {
            fatalError("Nazwisko nie może być puste.")
        }

        print("Podaj rok urodzenia:")
        guard let rokUrodzenia = Int(readLine()!) else {
            fatalError("Rok urodzenia musi być liczbą całkowitą.")
        }

        print("Podaj numer indeksu:")
        guard let nrIndeksu = Int(readLine()!) else {
            fatalError("Numer indeksu musi być liczbą całkowitą.")
        }

        print("Podaj numer kierunku (1 - Informatyka, 2 - Mechatronika, \n3 - Architektura, 4 - Budownictwo):")

        guard let wybor = readLine(), let numerKierunku = Int(wybor) else {
            fatalError("Podano niepoprawny numer.")
        }

        let kierunek: Student.Kierunek

        switch numerKierunku {
        case 1:
            kierunek = Student.Kierunek.Informatyka
        case 2:
            kierunek = Student.Kierunek.Mechatronika
        case 3:
            kierunek = Student.Kierunek.Architektura
        case 4:
            kierunek = Student.Kierunek.Budownictwo
        default:
            fatalError("Podany kierunek nie istnieje.")
        }

        print("Podaj rok studiów:")
        guard let rokStudiow = Int(readLine()!) else {
            fatalError("Rok studiów musi być liczbą całkowitą.")
        }

        var oceny: [String: Double] = [:]
        for przedmiot in ["Matematyka", "Fizyka", "Inżynieria", "OWI", "BHP"] {
            print("Podaj ocenę z \(przedmiot):")
            guard let ocena = Double(readLine()!) else {
                fatalError("Ocena musi być liczbą zmiennoprzecinkową.")
            }

            oceny[przedmiot] = ocena
        }

        // Tworzymy obiekt klasy Student i dodajemy go do listy
        let student = Student(imie: imie, nazwisko: nazwisko, rokUrodzenia: rokUrodzenia, nrIndeksu: nrIndeksu, kierunek: kierunek, rokStudiow: rokStudiow, oceny: oceny)
        studenci.append(student)
    }

    return studenci
}

var studenci: [Student] = wczytaj();

for student: Student in studenci{ 
    print(student.dane());
}

// Zadanie 11.4

import Foundation

class StudentNaErasmusie: Student {
    private var uczelniaZagraniczna: String
    private var dataRozpoczecia: String
    private var dataZakonczenia: String
    private var kursy: [String: Double]

    // Inicjalizator
    init(imie: String, nazwisko: String, rokUrodzenia: Int, nrIndeksu: Int, kierunek: Kierunek, rokStudiow: Int, oceny: [String: Double], uczelniaZagraniczna: String, dataRozpoczecia: String, dataZakonczenia: String, kursy: [String: Double]) {
        self.uczelniaZagraniczna = uczelniaZagraniczna
        self.dataRozpoczecia = dataRozpoczecia
        self.dataZakonczenia = dataZakonczenia
        self.kursy = kursy

        // Wywołanie inicjalizatora klasy bazowej (Student)
        super.init(imie: imie, nazwisko: nazwisko, rokUrodzenia: rokUrodzenia, nrIndeksu: nrIndeksu, kierunek: kierunek, rokStudiow: rokStudiow, oceny: oceny)
    }

    // Funkcja do wyświetlania danych studenta na Erasmusie
    func wyswietlDaneNaErasmusie() {
        // Wywołujemy metodę dziedziczoną z klasy Student
        print("Imię i nazwisko: \(dane())")
        print("Numer indeksu: \(nrIndeksu)")
        print("Kierunek: \(kierunek)")
        print("Rok studiów: \(rokStudiow)")
        print("Uczelnia zagraniczna: \(uczelniaZagraniczna)")
        print("Data rozpoczęcia: \(dataRozpoczecia)")
        print("Data zakończenia: \(dataZakonczenia)")
        
        // Wyświetlamy kursy i oceny
        print("Kursy na Erasmusie:")
        for (kurs, ocena) in kursy {
            print("- \(kurs): \(ocena)")
        }
    }

    // Funkcja do obliczania czasu spędzonego na Erasmusie
    func czasNaErasmusie() -> String {
        let formatter = DateFormatter()
        formatter.dateFormat = "yyyy-MM-dd"
        
        if let startDate = formatter.date(from: dataRozpoczecia),
           let endDate = formatter.date(from: dataZakonczenia) {
            let calendar = Calendar.current
            let components = calendar.dateComponents([.day], from: startDate, to: endDate)
            
            if let days = components.day {
                return "\(days) dni"
            }
        }
        
        return "Błąd w datach"
    }

    // Funkcja do obliczania średniej oceny z kursów
    func sredniaOcena() -> Double {
        let sum = kursy.values.reduce(0.0, +)
        return sum / Double(kursy.count)
    }
}

