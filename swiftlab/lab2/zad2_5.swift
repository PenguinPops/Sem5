import Foundation

let a: Int = Int.random(in:1...9)
let b: Int = Int.random(in:1...9)
let c: Int = Int.random(in:1...9)

let srednia: Float = Float(a + b + c) / 3

print("Liczby to: \(a), \(b), \(c), a srednia arytm to: \(srednia)")