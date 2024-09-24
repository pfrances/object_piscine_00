#include "Bank.hpp"

unsigned int Bank::Account::_accountIndex = 0;

Bank::Account::Account(const unsigned int value) : _id(Account::_accountIndex), _value(value)
{
    Bank::Account::_accountIndex++;
}

Bank::Account::Account() : _id(Account::_accountIndex), _value(0)
{
    Bank::Account::_accountIndex++;
}

Bank::Account::~Account()
{
}

unsigned int Bank::Account::getId() const
{
    return (this->_id);
}

void Bank::Account::addValue(const unsigned int value)
{
    this->_value += value;
}

unsigned int Bank::Account::getValue() const
{
    return (this->_value);
}