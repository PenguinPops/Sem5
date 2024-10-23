
print("Podaj znak")
let char = readLine()!

switch char {
    case "a", "e", "i", "o", "u", "y":
        print("Podany znak to samogłoska")
    case "b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "z":
        print("Podany znak to spółgłoska")
    case "0", "1", "2", "3", "4", "5", "6", "7", "8", "9":
        print("Podany znak to cyfra")
    default:
        print("Podany znak to inny znak")
}