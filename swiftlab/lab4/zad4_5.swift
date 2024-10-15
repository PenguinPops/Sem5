import Foundation

print("Podaj kod pocztowy:")
let postalCode = readLine()!

switch postalCode.prefix(2) {
case "00", "01", "02", "03", "04", "05", "06", "07", "08", "09":
    print("Województwo Mazowieckie")
case "10", "11", "12", "13", "14", "15", "16", "17", "18", "19":
    print("Województwo Warmińsko-Mazurskie")
case "20", "21", "22", "23", "24":
    print("Województwo Lubelskie")
case "25", "26":
    print("Województwo Mazowieckie")
case "27", "28", "29":
    print("Województwo Świętokrzyskie")
case "30", "31", "32", "33", "34":
    print("Województwo Małopolskie")
case "35", "36", "37", "38", "39":
    print("Województwo Podkarpackie")
case "40", "41", "42", "43", "44":
    print("Województwo Śląskie")
case "45", "46", "47":
    print("Województwo Opolskie")
case "48", "49":
    print("Województwo Śląskie")
case "50", "51", "52", "53", "54":
    print("Województwo Dolnośląskie")
case "55", "56", "57", "58", "59":
    print("Województwo Dolnośląskie")
case "60", "61", "62", "63", "64":
    print("Województwo Wielkopolskie")
case "65", "66":
    print("Województwo Lubuskie")
case "67", "68":
    print("Województwo Wielkopolskie")
case "69":
    print("Województwo Lubuskie")
case "70", "71", "72", "73", "74":
    print("Województwo Zachodniopomorskie")
case "75", "76", "77":
    print("Województwo Opolskie")
case "78":
    print("Województwo Zachodniopomorskie")
case "79":
    print("Województwo Świętokrzyskie")
case "80", "81", "82", "83", "84":
    print("Województwo Pomorskie")
case "85", "86", "87", "88":
    print("Województwo Kujawsko-Pomorskie")
case "89":
    print("Województwo Pomorskie")
case "90", "91", "92", "93", "94":
    print("Województwo Łódzkie")
case "95", "96":
    print("Województwo Łódzkie")
case "97", "98":
    print("Województwo Mazowieckie")
case "99":
    print("Województwo Łódzkie")
default:
    print("Nieznany kod pocztowy")
}


