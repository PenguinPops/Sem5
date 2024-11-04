import Foundation
print("Zadanie 1")
for x in 1..<26 {
    print(x, terminator: " ")
}
print()
var x = 1
while(x != 26) {
    print(x, terminator: " ")
    x += 1
}
print()
x = 1
repeat {
    print(x, terminator: " ")
    x += 1
} while x != 26
print()

// -----------------------------------------------------

print("Zadanie 2")
for x in stride(from: 1, to: 26, by: 3) {
    print(x, terminator: " ")
}
print()
x = 1
while(x<26) {
    print(x, terminator: " ")
    x += 3
}
print()
x = 1
repeat {
    print(x, terminator: " ")
    x += 3
} while x < 26
print()

// -----------------------------------------------------

print("Zadanie 3")
print("Wprowadź liczbę kończącą ciąg fibonacciego: ", terminator: "")
guard let licz = Int(readLine()!) else { fatalError("Nieprawidłowa wartość") }
var a = 0
var b = 1
var c = 0
while a <= licz {
    print(a, terminator: " ")
    c = a + b
    a = b
    b = c
}
print()

// -----------------------------------------------------

print("Zadanie 4")
print("Wprowadź liczbę aby sprawdzić czy jest pierwsza: ", terminator: "")
guard let licz2 = Int(readLine()!) else { fatalError("Nieprawidłowa wartość") }
var isPrime = true
if licz2 <= 1 {
    isPrime = false
} else {
    var x = 2
    let y = Int(Double(licz2).squareRoot())
    while x <= y {
        if licz2 % x == 0 {
            isPrime = false
            break
        }
        x += 1
    }
}
if isPrime {
    print("Liczba jest pierwsza")
} else {
    print("Liczba nie jest pierwsza")
}
print()

// -----------------------------------------------------

print("Zadanie 5")
repeat {
    print("Wczytaj liczbe trzycyfrową: ", terminator: "")
    guard let input = readLine(), let number = Int(input), number >= 100, number <= 999 else {
        print("Nieprawidłowa wartość, spróbuj ponownie.")
        continue
    }
    x = number
    break
} while true
var suma = 0
while x > 0 {
    suma += x % 10
    x /= 10
}
print("Suma cyfr liczby wynosi: \(suma)")
print()

// -----------------------------------------------------

print("Zadanie 6")
print("Wprowadź ciąg znaków do sprawdzenia czy jest palindromem: ", terminator: "")
let palindrom = readLine()!
var pal = true
for i in 0..<palindrom.count/2 {
    if palindrom[palindrom.index(palindrom.startIndex, offsetBy: i)] != palindrom[palindrom.index(palindrom.startIndex, offsetBy: palindrom.count - i - 1)] {
        pal = false
    }
}
if pal {
    print("Ciąg znaków jest palindromem")
} else {
    print("Ciąg znaków nie jest palindromem")
}
print()

// -----------------------------------------------------

print("Zadanie 7")
var sum = 0
var i = 0
while i <= 7{
    if i % 2 != 0 {
        sum += i
    }
    i+=1
}
print("Suma elementów wynosi \(sum)")

