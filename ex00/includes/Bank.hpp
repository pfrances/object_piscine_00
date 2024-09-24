#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <map>

struct Bank
{

private:
    struct Account
    {
    private:
        unsigned int _id;
        unsigned int _value;
        static unsigned int _accountIndex;

    public:
        Account(const unsigned int value);
        Account();
        ~Account();

        unsigned int getId() const;

        void addValue(const unsigned int value);
        unsigned int getValue() const;

        friend std::ostream &operator<<(std::ostream &p_os, const Account &p_account)
        {
            p_os << "[" << p_account.getId() << "] - [" << p_account.getValue() << "]";
            return (p_os);
        }
    };

    unsigned int _liquidity;
    std::map<unsigned int, Account *> _clientAccounts;
    static const unsigned int _DEPOSIT_FEE_PERCENTAGE = 5;

    Account *operator[](const unsigned int id);
    Account &getAccountRefById(const unsigned int id);

public:
    Bank(const unsigned int liquidity);
    Bank();
    ~Bank();

    int CreateAccount(const unsigned int value);
    void DeleteAccount(const unsigned int id);

    int AccountBalance(const unsigned int id);

    void AccountDeposit(const unsigned int id, const unsigned int value);
    void AccountWithdraw(const unsigned int id, const unsigned int value);

    int getLiquidity() const;
    void AddLiquidity(const unsigned int value);
    void removeLiquidity(const unsigned int value);

    void Loan(const unsigned int id, const unsigned int value);

    friend std::ostream &
    operator<<(std::ostream &p_os, const Bank &p_bank);

    class InvalidAccountId : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Invalid account id";
        }
    };

    class NotEnoughLiquidity : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Not enough liquidity";
        }
    };

    class NotEnoughFunds : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Not enough funds";
        }
    };
};

#endif