print("Wczytaj 2 liczby całkowite")
let a = Int(readLine()!)!
let b = Int(readLine()!)!

print("1-dodawanie, 2-odejmowanie, 3-mnożenie, 4-dzielenie")
let choice = Int(readLine()!)!

switch choice {
    case 1:
        print("Wynik dodawania: \(a+b)")
    case 2:
        print("Wynik odejmowania: \(a-b)")
    case 3:
        print("Wynik mnożenia: \(a*b)")
    case 4:
        if(b == 0) { print("Nie można dzielić przez 0") }
        else { print("Wynik dzielenia: \(a/b)") }
    default:
        print("Podano nieprawidłową wartość")
}

