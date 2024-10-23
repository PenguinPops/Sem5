import Foundation
print("Podaj rok")
guard let year = Int(readLine()!) else {
fatalError("To nie jest liczba całkowita")
}
if(year >= 0) {
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) { 
        print("Rok jest przestępny") }
    else { print("Rok nie jest przestępny") }
} else {
    print("Podano nieprawidłową wartość")
}
