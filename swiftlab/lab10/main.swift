// zadania 10.1, 10.3 oraz 10.4

// Zadanie 10.1

// Polecenie 1

func losujLiczbe() -> Int {
    return Int.random(in: 1...100);
}

func losuj3Liczby() -> (Int, Int, Int) {
    return (losujLiczbe(), losujLiczbe(), losujLiczbe());
}

// Polecenie 2

func najwiekszaZ3(_ a: Int, _ b: Int, _ c: Int) -> Int {
    return max(a, max(b, c));
}

// Polecenie 3

func najmniejszaZ3(_ a: Int, _ b: Int, _ c: Int) -> Int { // _ - pomija nazwę argumentu :Int - typ argumentu -> Int - typ zwracany
    return min(a, min(b, c));
}

// Polecenie 4

func zwrocSkrajne(_ a: Int, _ b: Int, _ c: Int) -> () {
    print("Najmniejsza z 3 liczb: ", terminator: "");
    print(najmniejszaZ3(a, b, c), terminator: ", ");
    print("Największa z 3 liczb: ", terminator: "");
    print(najwiekszaZ3(a, b, c));
}

let liczby: (Int, Int, Int) = losuj3Liczby();
print("3 losowe liczby: ", terminator: "");
print(liczby);
zwrocSkrajne(liczby.0, liczby.1, liczby.2)

// Zadanie 10.3

// Polecenie 1. Napisz program konsolowy, który wczyta współrzędne dwóch punktów układu
// współrzędnych. Należy napisać funkcję wczytującą współrzędne i je zwracające


func dwaPkt() -> (Double, Double, Double, Double) {
    print("Podaj współrzędną x punktu 1: ", terminator:"")
    guard let x1: Double = Double(readLine()!) else { fatalError("🐶") }
    print("Podaj współrzędną y punktu 1: ", terminator:"")
    guard let y1: Double = Double(readLine()!) else { fatalError("🐶") }
    print("Podaj współrzędną x punktu 2: ", terminator:"")
    guard let x2: Double = Double(readLine()!) else { fatalError("🐶") }
    print("Podaj współrzędną y punktu 2: ", terminator:"")
    guard let y2: Double = Double(readLine()!) else { fatalError("🐶") }

    return (x1, y1, x2, y2)
}


// Polecenie 2. Napisz funkcję obliczającą odległość między wczytanymi punktami.

import Foundation

func odlegloscMiedzyPkt( _ x1:Double, _ y1:Double, _ x2:Double, _ y2:Double ) -> Double {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Polecenie 3. Napisz funkcję zwracającą numer ćwiartki, w której leży dany punkt.

func numerCwiartki( _ x:Double, _ y:Double ) -> Int {
    if(x<0) {
        if(y<0) {return 4;}
        else {return 1;}
    }
    else {
        if(y<0) {return 3;}
        else {return 2;}
    }
}

// Polecenie 4. Napisz funkcję, która sprawdzi, czy dany punkt leży wewnątrz okręgu na jego
// obwodzie, czy poza nim. Okrąg ma środek w (0,0)

func sprawdzOkrag( _ x: Double, _ y: Double) {
    print("Podaj promień okręgu: ", terminator: "")
    guard let promien = Double(readLine()!), promien > 0 else { fatalError("🐶") }

    let odlegloscOdSrodka = sqrt(pow(x, 2) + pow(y, 2))

    if odlegloscOdSrodka < promien {
        print("Punkt (\(x), \(y)) znajduje się wewnątrz okręgu.")
    } else if odlegloscOdSrodka == promien {
        print("Punkt (\(x), \(y)) znajduje się na obwodzie okręgu.")
    } else {
        print("Punkt (\(x), \(y)) znajduje się poza okręgiem.")
    }
}

// Polecenie 5. Przetestuj polecenia.

let (x1, y1, x2, y2) = dwaPkt();
print("Punkt 1: (\(x1), \(y1)), punkt 2: (\(x2), \(y2))");
print("Odleglosc miedzy tymi punktami: ", terminator:"");
print(odlegloscMiedzyPkt(x1, y1, x2, y2));
print("Numer cwiartki pkt 1: ", terminator: "");
print(numerCwiartki(x1, y1));
print("Numer cwiartki pkt 2: ", terminator: "");
print(numerCwiartki(x2, y2));
print("Zależność pkt 1 co do okręgu:");
sprawdzOkrag(x1, y1);
print("Zależność pkt 2 co do okręgu:");
sprawdzOkrag(x2, y2);

// Zadanie 10.4

// Polecenie 1. Napisz program konsolowy, który wczyta liczbę elementów tablicy oraz jej
// elementy całkowite, a następnie wyznaczy największy element, najmniejszy element oraz
// średnią arytmetyczną wszystkich elementów.

print("Podaj liczbe elementow tablicy ", terminator: "")
guard let wielkosc = Int(readLine()!), wielkosc > 0 else { fatalError("🐶") }

var tablica: [Double] = []

for _ in 0..<wielkosc {
    print("Podaj element tablicy: ", terminator: "")
    guard let element = Double(readLine()!) else { fatalError("🐶") }
    tablica.append(element)
}

func najwiekszyElement(_ tablica: [Double]) -> Double {
    return tablica.max()!
}

func najmniejszyElement(_ tablica: [Double]) -> Double {
    return tablica.min()!
}

func sredniaArytmetyczna(_ tablica: [Double]) -> Double {
    return tablica.reduce(0, +) / Double(tablica.count)
}

// Polecenie 2. Napisz funkcję, która wczyta elementy do tablicy i zwróci tą tablicę. Funkcja
// powinna posiadać parametr mówiący o liczbie elementów tablicy.

func wczytajTablice(_ wielkosc: Int) -> [Double] {
    var tablica: [Double] = []

    for _ in 0..<wielkosc {
        print("Podaj element tablicy: ", terminator: "")
        guard let element = Double(readLine()!) else { fatalError("🐶") }
        tablica.append(element)
    }

    return tablica
}

// Polecenie 3. Napisz funkcję, która wyświetli wszystkie elementy tablicy.

func wyswietlTablice(_ tablica: [Double]) {
    print("Tablica: ", terminator: "")
    print(tablica)
}

// Polecenie 4. Napisz funkcję, która wyznaczy i zwróci najmniejszy element tablicy oraz
// indeks, na którym się znajduje.

func najmniejszyElementZIndeksem(_ tablica: [Double]) -> (Double, Int) {
    let minElement = tablica.min()!
    let index = tablica.firstIndex(of: minElement)!
    return (minElement, index)
}

// Polecenie 5. Napisz funkcję, która wyznaczy i zwróci największy element tablicy oraz indeks,
// na którym się znajduje.

func najwiekszyElementZIndeksem(_ tablica: [Double]) -> (Double, Int) {
    let maxElement = tablica.max()!
    let index = tablica.firstIndex(of: maxElement)!
    return (maxElement, index)
}

// Polecenie 6. Napisz funkcję, która zamieni miejscami element największy z najmniejszym.

func zamienMiejscamiNajwiekszyNajmniejszy(_ tablica: inout [Double]) {
    let (minElement, minIndex) = najmniejszyElementZIndeksem(tablica)
    let (maxElement, maxIndex) = najwiekszyElementZIndeksem(tablica)

    tablica[minIndex] = maxElement
    tablica[maxIndex] = minElement
}

// Polecenie 7. Napisz funkcję, która wyznaczy i zwróci średnią arytmetyczną wszystkich
// elementów tablicy.

func sredniaArytmetycznaTablicy(_ tablica: [Double]) -> Double {
    return tablica.reduce(0, +) / Double(tablica.count)
}

// Polecenie 8. Przetestuj utworzone funkcje.

print("Tablica: ", terminator: "")
print(tablica)
print("Największy element: ", terminator: "")
print(najwiekszyElement(tablica))
print("Najmniejszy element: ", terminator: "")
print(najmniejszyElement(tablica))
print("Średnia arytmetyczna: ", terminator: "")
print(sredniaArytmetyczna(tablica))

let tablica2 = wczytajTablice(wielkosc)
wyswietlTablice(tablica2)

let (minElement, minIndex) = najmniejszyElementZIndeksem(tablica2)
print("Najmniejszy element: ", terminator: "")
print(minElement)
print("Indeks: ", terminator: "")
print(minIndex)

let (maxElement, maxIndex) = najwiekszyElementZIndeksem(tablica2)
print("Największy element: ", terminator: "")
print(maxElement)
print("Indeks: ", terminator: "")
print(maxIndex)

zamienMiejscamiNajwiekszyNajmniejszy(&tablica2)
print("Tablica po zamianie miejscami największego i najmniejszego elementu: ", terminator: "")
print(tablica2)

print("Średnia arytmetyczna tablicy: ", terminator: "")
print(sredniaArytmetycznaTablicy(tablica2))
