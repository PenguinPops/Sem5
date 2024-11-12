import Foundation;

let num = (Double.random(in: 50...60)).rounded()/10;
print(num);

let pesel = "03223201321"
// let index1 = pesel.startIndex;
// let index2 = pesel.index(pesel.startIndex, offsetBy: 1);
// let index3 = pesel.index(pesel.startIndex, offsetBy:2);
let peselArray = Array(pesel);
let rokUr = String(peselArray[0...1]);

if(peselArray[2] == "2") {
    print("Rok urodzenia: 20\(rokUr)");
    print("Miesiac urodzenia: ", terminator:"");
    print(String(Int(String(peselArray[2...3]))!-20))
}
else {
    print("Rok urodzenia: 19\(rokUr)");
    print("Miesiac urodzenia: ", terminator:"");
    print(String(peselArray[2...3]));
}

if let digit = Int(String(peselArray[10])), [0,2,4,6,8].contains(digit) {
    print("Płeć żeńska");
}
else{
    print("Płeć męska");
}

var y = 0;
var tab: [Double] = [];
for x in 1...5 {
    print("Wczytaj liczbe \(x) z 5: ", terminator:"");
    guard let input: String = readLine(),let y = Double(input) 
    else {fatalError("Zła wartość")}
    tab.append(y);
}
print(tab);
tab.sort();
print(tab);
var temp = tab.first;
// for x in 0..<(tab.count-1)/2 {
//     temp = tab[x];
//     tab[x] = tab[tab.count-1-x];
//     tab[tab.count-1-x] = temp!;
// }
print(tab);
temp = tab.first;
for x in 0..<tab.count-1 {
    tab[x] = tab[x+1];
}
tab[tab.count-1] = temp!;
print(tab);


