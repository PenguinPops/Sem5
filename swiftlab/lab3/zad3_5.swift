let str1 = readLine();
let str2 = readLine();

if(str1 == str2) { print("Strings are the same") }
else { print("Strings are different") }

let prefix = readLine();

if(str1!.hasPrefix(prefix!)) { print("String 1 has this prefix") }
else { print("String 1 doesnt have this prefix") }

if(str2!.hasPrefix(prefix!)) { print("String 2 has this prefix") }
else { print("String 2 doesnt have this prefix") }

let suffix = readLine();

if(str1!.hasSuffix(suffix!)) { print("String 1 has this prefix") }
else { print("String 1 doesnt have this prefix") }

if(str2!.hasSuffix(suffix!)) { print("String 2 has this suffix") }
else { print("String 2 doesnt have this suffix") }