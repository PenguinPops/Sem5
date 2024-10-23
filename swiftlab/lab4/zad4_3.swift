print("Podaj średnią ze studiów")
guard let average = Double(readLine()!) else {
    fatalError("To nie jest liczba zmiennoprzecinkowa")
}
switch average {
    case 2.0 ..< 3.0:
        print("Stypendium wynosi 0")
    case 3.0 ..< 4.0:
        print("Stypendium wynosi 100 zł")
    case 4.0 ..< 4.5:
        print("Stypendium wynosi 150 zł")
    case 4.5 ..< 5.0:
        print("Stypendium wynosi 200 zł")
    default:
        print("Podano nieprawidłową średnią")
}
