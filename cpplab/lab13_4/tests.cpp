#include <string>
#include <stdexcept>
#include <gtest/gtest.h>

class BankAccount {
private:
    std::string last_name;
    std::string account_number;
    double balance;

public:
    // Konstruktor
    BankAccount(const std::string &lastName, const std::string &accountNumber, double initialBalance)
        : last_name(lastName), account_number(accountNumber), balance(initialBalance) {
        if (initialBalance < 0) {
            throw std::invalid_argument("Initial balance cannot be negative.");
        }
    }

    // Setter i getter dla last_name
    void setLastName(const std::string &lastName) { last_name = lastName; }
    std::string getLastName() const { return last_name; }

    // Setter i getter dla account_number
    void setAccountNumber(const std::string &accountNumber) { account_number = accountNumber; }
    std::string getAccountNumber() const { return account_number; }

    // Setter i getter dla balance
    void setBalance(double newBalance) {
        if (newBalance < 0) {
            throw std::invalid_argument("Balance cannot be negative.");
        }
        balance = newBalance;
    }
    double getBalance() const { return balance; }

    // Metoda add
    void add(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Amount to add must be positive.");
        }
        balance += amount;
    }

    // Metoda withdraw
    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Amount to withdraw must be positive.");
        }
        if (balance - amount < 0) {
            throw std::invalid_argument("Insufficient balance.");
        }
        balance -= amount;
    }

    // Metoda isMillionaire
    bool isMillionaire() const {
        return balance >= 1000000.0;
    }
};

// Testy Google Test
class BankAccountTest : public ::testing::Test {
protected:
    BankAccount *account;

    void SetUp() override {
        account = new BankAccount("Kowalski", "1234567890", 500.0);
    }

    void TearDown() override {
        delete account;
    }
};

// Test konstruktora
TEST_F(BankAccountTest, ConstructorInitializesFieldsCorrectly) {
    EXPECT_EQ(account->getLastName(), "Kowalski");
    EXPECT_EQ(account->getAccountNumber(), "1234567890");
    EXPECT_DOUBLE_EQ(account->getBalance(), 500.0);
}

// Test add
TEST_F(BankAccountTest, AddPositiveAmountIncreasesBalance) {
    account->add(200.0);
    EXPECT_DOUBLE_EQ(account->getBalance(), 700.0);
}

TEST_F(BankAccountTest, AddNegativeAmountThrowsException) {
    EXPECT_THROW(account->add(-100.0), std::invalid_argument);
}

// Test withdraw
TEST_F(BankAccountTest, WithdrawPositiveAmountDecreasesBalance) {
    account->withdraw(300.0);
    EXPECT_DOUBLE_EQ(account->getBalance(), 200.0);
}

TEST_F(BankAccountTest, WithdrawNegativeAmountThrowsException) {
    EXPECT_THROW(account->withdraw(-100.0), std::invalid_argument);
}

TEST_F(BankAccountTest, WithdrawMoreThanBalanceThrowsException) {
    EXPECT_THROW(account->withdraw(600.0), std::invalid_argument);
}

// Test isMillionaire
TEST_F(BankAccountTest, IsMillionaireReturnsFalseWhenBalanceIsLessThanMillion) {
    EXPECT_FALSE(account->isMillionaire());
}

TEST_F(BankAccountTest, IsMillionaireReturnsTrueWhenBalanceIsMillionOrMore) {
    account->setBalance(1000000.0);
    EXPECT_TRUE(account->isMillionaire());
}

// Testy parametryczne dla metody add
class AddTest : public ::testing::TestWithParam<std::tuple<double, double>> {};

TEST_P(AddTest, AddValidAmountIncreasesBalance) {
    double initialBalance = 500.0;
    double amountToAdd = std::get<0>(GetParam());
    double expectedBalance = std::get<1>(GetParam());

    BankAccount account("Kowalski", "1234567890", initialBalance);
    account.add(amountToAdd);

    EXPECT_DOUBLE_EQ(account.getBalance(), expectedBalance);
}

INSTANTIATE_TEST_SUITE_P(
    ValidAdditions,
    AddTest,
    ::testing::Values(
        std::make_tuple(100.0, 600.0),
        std::make_tuple(200.0, 700.0),
        std::make_tuple(300.0, 800.0))
);

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
