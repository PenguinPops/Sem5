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

// var tab: [Int] = [];
// var sum = 0;
// for _ in 0...2 {
//     tab.append(Int.random(in: 1...9));
//     sum += tab.last!;
// }
// print("Tablica: \(tab), srednia: \(((Double(sum)/Double(tab.count))*100).rounded()/100)");


// var Oceny: [Int] = [];
// var SumaTop = 0;
// var SumaBot = 0;
// var Wagi: [Int] = [];
// for x in 1...3 {
//     print("Wpisz \(x) ocenę: ", terminator:"");
//     guard let y = readLine(), let ocena = Int(y), ocena > 0, ocena < 7 else {fatalError("Źle")}
//     Oceny.append(ocena);
//     print("Wpisz \(x) wagę: ", terminator:"");
//     guard let z = readLine(), let waga = Int(z), waga > 0, waga < 4 else {fatalError("Źle")}
//     Wagi.append(waga);
//     SumaTop += ocena * waga;
//     SumaBot += waga;
// }
// print("Oceny: \(Oceny), Wagi: \(Wagi), Średnia ważona: \(Double(SumaTop)/Double(SumaBot))")


// print("Podaj imie: ", terminator:"");
// guard let imie: String = readLine() else {fatalError("Źle")}
// print("Podaj drugieImie: ", terminator:"");
// guard let drugieImie: String = readLine() else {fatalError("Źle")}
// print("Podaj nazwisko: ", terminator:"");
// guard let nazwisko: String = readLine() else {fatalError("Źle")}
// print("Podaj rokUr: ", terminator:"");
// guard let y: String = readLine(), let rokUr = Int(y), rokUr > 1900, rokUr < 2024  else {fatalError("Źle")}

// var mainString = "Dane: " + imie + " " + drugieImie + " " + nazwisko + " " + String(rokUr) + ".";
// print(mainString);
// var firstIndex = mainString.index(mainString.startIndex, offsetBy: (7+imie.count));
// var lastIndex = mainString.index(mainString.startIndex, offsetBy: (7+imie.count+drugieImie.count));
// mainString.removeSubrange(firstIndex...lastIndex);
// print(mainString);
// firstIndex = mainString.index(mainString.endIndex, offsetBy: -6);
// lastIndex = mainString.index(firstIndex, offsetBy: 5);
// mainString.removeSubrange(firstIndex..<lastIndex)
// print(mainString);
// if(imie.hasPrefix(String("D"))) {
//     print("Imie zaczyna sie na D");
// }
// else {
//     print("Imie nie zaczyna sie na D");
// }

// guard let x = readLine(), let rok = Int(x), rok > 0 else { fatalError("Nie")}
// if((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0) {
//     print("Rok jest przestępczy");
// }
// else {
//     print("Rok nieprzestępczy");
// }

// guard let y = readLine(), let year = Int(y), year > 1, year < 3011 else {fatalError()}
// var wiek = ((year-1)/100)+1
// //zamien wiek na rzymskie
// var rzymska = "";

// while(wiek > 0) {
//     switch wiek {
//         case _ where wiek >= 10:
//             rzymska += "X";
//             wiek -= 10;
//         case _ where wiek >= 9:
//             rzymska += "IX";
//             wiek -= 9;
//         case _ where wiek >= 5:
//             rzymska += "V";
//             wiek -= 5;
//         case _ where wiek >= 4:
//             rzymska += "IV";
//             wiek -= 4;
//         default:
//             rzymska += "I";
//             wiek -= 1;
//     }
// }
// print("Rok \(year) to wiek \(rzymska)");

let srednia = 4.5;
switch(srednia) {
    case 0 ..< 3.0:
        print("0");
    case 3.0 ..< 4.0:
        print("100")
    case 4.0 ..< 4.5:
        print("150")
    case 4.5 ... 5.0:
        print("200")
    default:
        print("Źle")
}