import Foundation

struct liczbaZespolona {
    var re: Double
    var im: Double
    init(re: Double, im: Double) {
        self.re = re
        self.im = im
    }
}

func dodaj(_ a: liczbaZespolona, _ b: liczbaZespolona) -> liczbaZespolona {
    return liczbaZespolona(re: a.re + b.re, im: a.im + b.im);
}

func odejmij(_ a: liczbaZespolona, _ b: liczbaZespolona) -> liczbaZespolona {
    return liczbaZespolona(re: a.re - b.re, im: a.im - b.im);
}

func pomnoz(_ a: liczbaZespolona, _ b: liczbaZespolona) -> liczbaZespolona {
    return liczbaZespolona(re: a.re * b.re - a.im * b.im, im: a.re * b.im + a.im * b.re);
}

func menu() {
    print("1. Dodawanie");
    print("2. Odejmowanie");
    print("3. Mnożenie");
    print("4. Wyjście");
}

var a: liczbaZespolona = liczbaZespolona(re: 4, im: 3);
var b: liczbaZespolona = liczbaZespolona(re: 1, im: 5);
var wybor: Int = 0;

while wybor != 4 {
    menu();
    print("Wybierz operację: ", terminator: "");
    guard let x = Int(readLine()!) else { fatalError("🐶") }
    wybor = x;
    switch wybor {
    case 1:
        print("Wynik dodawania: \(dodaj(a, b).re) + \(dodaj(a, b).im)i");
    case 2:
        print("Wynik odejmowania: \(odejmij(a, b).re) + \(odejmij(a, b).im)i");
    case 3:
        print("Wynik mnożenia: \(pomnoz(a, b).re) + \(pomnoz(a, b).im)i");
    case 4:
        break;
    default:
        print("Niepoprawny wybór");
    }
}

// Zadanie 2

struct rzutOszczepem {
    var idOsoby: Int
    var proba1: Double
    var proba2: Double
    var proba3: Double
}

let zawodnik1 = rzutOszczepem(idOsoby: 1, proba1: 50.0, proba2: 60.0, proba3: 70.0)
let zawodnik2 = rzutOszczepem(idOsoby: 2, proba1: 40.0, proba2: 50.0, proba3: 60.0)
let zawodnik3 = rzutOszczepem(idOsoby: 3, proba1: 30.0, proba2: 40.0, proba3: 50.0)
let zawodnik4 = rzutOszczepem(idOsoby: 4, proba1: 20.0, proba2: 30.0, proba3: 40.0)

var tablicaZawodnikow: [(rzutOszczepem, sredniDystans: Double)] = [(zawodnik1, (zawodnik1.proba1 + zawodnik1.proba2 + zawodnik1.proba3) / 3), (zawodnik2, (zawodnik2.proba1 + zawodnik2.proba2 + zawodnik2.proba3) / 3), (zawodnik3, (zawodnik3.proba1 + zawodnik3.proba2 + zawodnik3.proba3) / 3), (zawodnik4, (zawodnik4.proba1 + zawodnik4.proba2 + zawodnik4.proba3) / 3)];

print("Najwieksza srednia osiagnal zawodnik: \(tablicaZawodnikow.max(by: { $0.sredniDystans < $1.sredniDystans })!.0.idOsoby) z wynikiem: \(tablicaZawodnikow.max(by: { $0.sredniDystans < $1.sredniDystans })!.sredniDystans)");

if let usunNajmnieszy = tablicaZawodnikow.firstIndex(where: { $0.sredniDystans == tablicaZawodnikow.min(by: { $0.sredniDystans < $1.sredniDystans })!.sredniDystans }) {
    tablicaZawodnikow.remove(at: usunNajmnieszy);
    print("Usunięto zawodnika z najmniejszą średnią");
}
else {
    print("Nie znaleziono zawodnika z najmniejszą średnią");
}

// Zadanie 3

var samochody: Set<String> = [];

samochody.insert("BMW");
samochody.insert("Audi");
samochody.insert("Mercedes");
samochody.insert("Volkswagen");
samochody.insert("Toyota");
samochody.insert("Suzuki");

for x in samochody {
    print("Samochód: \(x)", terminator:"\t");
}
print("\n");

guard let model = readLine() else { fatalError("🐶") }

if let usun = samochody.firstIndex(of: model) {
    samochody.remove(at: usun);
    print("Usunięto samochód: \(model)");
}
else {
    print("Nie znaleziono samochodu: \(model)");
}


// Zadanie 4

var student: [String: Int] = ["Jan Kowalski": 123456, "Adam Nowak": 654321, "Anna Wiśniewska": 987654, "Katarzyna Dąbrowska": 456789, "Piotr Lewandowski": 987123];

for (klucz, wartosc) in student {
    print("Student: \(klucz), numer indeksu: \(wartosc)");
}

print("Podaj numer indeksu: ", terminator: "");
guard let numer = Int(readLine()!) else { fatalError("🐶") }

if let znajdz = student.firstIndex(where: { $0.value == numer }) {
    print("Studenta z numerem indeksu: \(numer) ma nazwisko: \(student[student.index(znajdz, offsetBy: 0)].key)");
}
else {
    print("Nie znaleziono studenta z numerem indeksu: \(numer)");
}


if let usun = student.firstIndex(where: { $0.value == 123456 }) {
    student.remove(at: usun);
    print("Usunięto studenta z numerem indeksu: 123456");
}
else {
    print("Nie znaleziono studenta z numerem indeksu: 123456");
}
