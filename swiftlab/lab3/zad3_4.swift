import Foundation

print("Podaj ciąg znaków")
let ciag: String = readLine()!

print("Podaj znak")
let znak: Character = Character(readLine()!)

print("Podaj liczbę całkowitą")
let liczba: Int = Int(readLine()!)!

var test: Bool = false;

if(ciag.first == znak) {
    print("Znak znajduje się na początku ciągu")
    test = true
}
if(ciag.last == znak) {
    print("Znak znajduje się na końcu ciągu")
    test = true
}
if(ciag[ciag.index(ciag.startIndex, offsetBy: liczba)] == znak) {
    print("Znak znajduje się na indeksie oddalonym o \(liczba) od początku ciągu")
    test = true
}
if(ciag[ciag.index(ciag.endIndex, offsetBy: -liczba-1)] == znak) {
    print("Znak znajduje się na indeksie oddalonym o \(liczba) od końca ciągu")
    test = true
} 
if(!test) {
    print("Znak nie znajduje się w szukanych pozycjach ciągu")
}