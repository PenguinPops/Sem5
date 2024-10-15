import Foundation

print("Podaj PESEL:")
if let pesel = readLine() {
    if pesel.count != 11 {
        print("Podany PESEL jest niepoprawny")
    } else {
        let genderDigit = pesel[pesel.index(pesel.startIndex, offsetBy: 9)]

        switch genderDigit {
            case "0", "2", "4", "6", "8":
                print("Podany PESEL reprezentuje kobietę")
            case "1", "3", "5", "7", "9":
                print("Podany PESEL reprezentuje mężczyznę")
            default:
                print("Podany PESEL jest niepoprawny")
        }
    }
} else {
    print("Nie podano PESEL-u")
}