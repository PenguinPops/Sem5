// print("Podaj rok urodzenia: ", terminator:"");
// guard let y = readLine(), let x = Int(y), x>=1900, x<=2024 else {fatalError("Źle wprowadzona wartość")}
// print("Masz \(2024-x) lat");

// let PI: Double = Double.pi;
// print("Podaj promień koła: ", terminator:"");
// guard let y = readLine(), let x: Double = Double(y), x>0 else {fatalError("źle")}
// let pole: Double = ((PI * x * x)*100).rounded()/100;
// let obwod: Double = ((2 * PI * x)*100).rounded()/100;
// let promien: Double = ((x*100).rounded())/100;
// print("Pole: \(pole), obwod: \(obwod), promien: \(promien)");

var tab: [Int] = [];
var sum = 0;
for _ in 0...2 {
    tab.append(Int.random(in: 1...9));
    sum += tab.last!;
}
print("Tablica: \(tab), srednia: \(((Double(sum)/Double(tab.count))*100).rounded()/100)");

//AT91PSPIO


