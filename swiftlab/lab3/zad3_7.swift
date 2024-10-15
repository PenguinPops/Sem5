import Foundation

print("Podaj kwote w PLN")
let pln = Double(readLine()!)!

let result = pln / 3.9
print(String(format: "Wynik w dolarach: %.2f$", result))

