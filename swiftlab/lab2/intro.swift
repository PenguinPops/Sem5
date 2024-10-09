import Foundation

let pi = 3.14
var a = 4, str = "abc", c = 5.4329
    
print(pi, str)
print("Pi: \(pi), str: \(str)")
print("Pi: ",pi,", str: ",str)

var str2 = String(format: "%.2f", c)
print(str2)

var str3: String = "124"
var n: Int? = Int(str3) //! znak zapytania obsługuje wyjątki typu "abc"

print(n) //wyświetla optional(124)
print(n!) //wyświetla 124

var d = Int.random(in: 1..<10) // od 1 do 9
var e: Int = Int.random(in: 1...10) // od 1 do 10


