//
//  main.cpp
//  Ex_1


#include <iostream>

void setAccountNumber(const BankAccount& account, std::string accNumber) {
    //    getBalance();
//    BankAccount.number
    account.accountNumber = accNumber;
};

void setBalance(BankAccount& account, double balance) {
    account.BAFriend.balance = balance;
};


class BankAccount {
private:
    std::string accountNumber;
    double balance;
    
    void deposit(double amount) {
//        set balance
        setBalance(amount);
        std::cout << amount << " has been deposited to your bank account. \n";
    };
    
    void withdraw(double amount) {
        if (balance >= amount){
            // set balance
            setBalance(amount);
            std::cout << amount << " has been widthdrawn from your bank account. \n";

        } else {
            std::cout << "Not enough credits \n";
        };
    };
public:
    const std::string getAccountNumber () {
        return accountNumber;
    };
    const double getBalance () {
        return balance;
    };
    
    friend class BAFriend;
    
};



int main() {
    // insert code here...
    return 0;
}
