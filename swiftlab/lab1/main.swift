func randomInt() -> Int {
    return Int.random(in: 1...100)
}

func main() {
    // generate 3 random numbers
    let number1 = randomInt()
    let number2 = randomInt()
    let number3 = randomInt()
    // print the numbers
    print("The random numbers are \(number1), \(number2), and \(number3).")
    // calculate the sum
    let sum = number1 + number2 + number3
    // print the sum
    print("The sum of the numbers is \(sum).")
    // calculate the average
    let average = Double(sum) / 3
    // print the average
    print("The average of the numbers is \(average).")

}

func main2() {
    // read 3 numbers from user
    print("Please enter 3 integers:")
    // let number1 = readInteger() ?? 0
    // let number2 = readInteger() ?? 0
    // let number3 = readInteger() ?? 0
    // calculate sum
    // let sum = number1 + number2 + number3
    // print sum
    // print("The sum of the numbers is \(sum).")
    

}

main()