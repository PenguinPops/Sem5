print("Podaj rok")
let year = Int(readLine()!)!

if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0) { print("Rok jest przestępny") }
else { print("Rok nie jest przestępny") }
