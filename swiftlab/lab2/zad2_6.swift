import Foundation

print("Podaj ocene i wage 1 ucznia: ")

let ocena1: String = readLine()!
let waga1: String = readLine()!

print("Podaj ocene i wage 2 ucznia: ")

let ocena2: String = readLine()!
let waga2: String = readLine()!

print("Podaj ocene i wage 3 ucznia: ")

let ocena3: String = readLine()!
let waga3: String = readLine()!

let ocena1Int: Int = Int(ocena1)!
let waga1Int: Int = Int(waga1)!
let ocena2Int: Int = Int(ocena2)!
let waga2Int: Int = Int(waga2)!
let ocena3Int: Int = Int(ocena3)!
let waga3Int: Int = Int(waga3)!

let sredniaWazona: Float = Float(ocena1Int * waga1Int + ocena2Int * waga2Int + ocena3Int * waga3Int) / Float(waga1Int + waga2Int + waga3Int)

print("Srednia wazona wynosi: \(sredniaWazona)")