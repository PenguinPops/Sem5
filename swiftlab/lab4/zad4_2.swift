import Foundation

print("Podaj rok z zakresu <2,3010>")
let year = Int(readLine()!)!
if(year < 2 || year > 3010) { 
    print("Podano rok spoza zakresu <2,3010>")
    exit(1)
}

// Określ, który to wiek. Pełne stulecia np. rok 2000 to wiek XX, a nie XXI.
let century = (year % 100 == 0) ? year / 100 : year / 100 + 1

// Przelicz to na rzymskie
var roman = ""

// Najpierw określamy wielokrotności 10 dla stuleci (1000, 2000, itd.)
switch century {
    case 1..<11: roman += ""  // Nie ma potrzeby dodawania nic dla pierwszych 10 wieków
    case 11..<21: roman += "X" // Wiek 11-20 to dodatek "X" (np. XI, XII itd.)
    case 21..<31: roman += "XX" // Wiek 21-30 to dodatek "XX" (np. XXI, XXII)
    default: break
}

// Dodajemy odpowiednią wartość dla reszty wieków (1-9 w systemie rzymskim)
switch century % 10 {
    case 0: roman += "X"
    case 1: roman += "I"
    case 2: roman += "II"
    case 3: roman += "III"
    case 4: roman += "IV"
    case 5: roman += "V"
    case 6: roman += "VI"
    case 7: roman += "VII"
    case 8: roman += "VIII"
    case 9: roman += "IX"
    default: break
}

print("Rok \(year) to wiek \(roman)")
