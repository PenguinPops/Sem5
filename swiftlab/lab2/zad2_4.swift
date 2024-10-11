import Foundation

print("Podaj a, b, z, s oraz cenę listwy za m2")

let a: String = readLine()!
let b: String = readLine()!
let z: String = readLine()!
let s: String = readLine()!
let cenaM: String = readLine()!

let aFloat: Float = Float(a)!
let bFloat: Float = Float(b)!
let zFloat: Float = Float(z)!
let cenaMFloat: Float = Float(cenaM)!

let obwod: Float = 2 * aFloat + 4 * bFloat + 2 * zFloat - 2 * Float(s)!
let cena: Float = obwod * cenaMFloat

print("Potrzebne jest \(obwod) m listwy")
print("Cena wynosi \(cena) zł")



