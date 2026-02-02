// bank_account.h - Simle bank account class definition
#pragma once
#include <stdexcept>

class BankAccount
{
    // private class member not visible outside the class
    // private:
    unsigned _balance; // the amount of money in the account
public:
    // public member functions visible outside the class
    constexpr BankAccount(unsigned balance = 0) // construct account with default balance 0
        : _balance(balance)                     // copy initial balance to private member _balance
    {
        // throw exception if negative balance
        if (_balance < 0)
        {
            throw std::runtime_error("balance must be non-negative");
        }
    }
    // controlled access to private data
    constexpr unsigned balance() const // does not change any class members
    {
        return _balance;
    }
    constexpr unsigned withdraw(unsigned amount)
    {
        // throw exception if amount > _balance
        if (amount > _balance)
        {
            throw std::runtime_error("insufficient funds");
        }
        _balance -= amount;

        return _balance;
    }
    constexpr unsigned deposit(unsigned amount)
    {
        // throw exception if addition would cause overflow
        if (_balance > ((unsigned)(-1) - amount))
        {
            throw std::runtime_error("deposit would cause overflow");
        }
        _balance += amount;

        return _balance;
    }
}; // <-- classes must have a trailing semicolon
