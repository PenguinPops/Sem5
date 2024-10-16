let str1 = readLine();
let str2 = readLine();

if(str1 == str2) { print("Ciągi są takie same") }
else { print("Ciągi są różne") }

let prefix = readLine();

if(str1!.hasPrefix(prefix!)) { print("Ciąg 1 ma ten prefix") }
else { print("Ciąg 1 nie ma tego prefixu") }

if(str2!.hasPrefix(prefix!)) { print("Ciąg 2 ma ten prefix") }
else { print("Ciąg 2 nie ma tego prefixu") }

let suffix = readLine();

if(str1!.hasSuffix(suffix!)) { print("Ciąg 1 ma ten suffix") }
else { print("Ciąg 1 nie ma tego suffixu") }

if(str2!.hasSuffix(suffix!)) { print("Ciąg 2 ma ten suffix") }
else { print("Ciąg 2 nie ma tego suffixu") }