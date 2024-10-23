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

print("Zadanie 3")
print("Wprowadź liczbę: ", terminator: "")
let licz = Int(readLine()!)!
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

print("Zadanie 4") 
print("Wprowadź liczbę: ", terminator: "")
let licz2 = Int(readLine()!)!
var pierw = false
x = 2
while x < licz2/2 {
    if licz2 % x != 0 {
        pierw = true
    }
    x += 1
}
if pierw {
    print("Liczba jest pierwsza")
} else {
    print("Liczba nie jest pierwsza")
}
print()

print("Zadanie 5")
repeat{
    print("Wcztaj liczbe trzycyfrową: ", terminator: "")
    x = Int(readLine()!)!
} while x > 999 || x < 100
var suma = 0
while x > 0 {
    suma += x % 10
    x /= 10
}
print("Suma cyfr liczby wynosi: \(suma)")

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

