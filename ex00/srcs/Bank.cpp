#include "Bank.hpp"

Bank::Bank(const unsigned int liquidity) : _liquidity(liquidity)
{
}

Bank::Bank() : _liquidity(0)
{
}

Bank::~Bank()
{
	for (std::map<unsigned int, Account *>::iterator it = _clientAccounts.begin(); it != _clientAccounts.end(); it++)
		delete it->second;
	_clientAccounts.clear();
}

Bank::Account *Bank::operator[](const unsigned int id)
{
	return _clientAccounts[id];
}

Bank::Account &Bank::getAccountRefById(const unsigned int id)
{
	Bank::Account *account = (*this)[id];
	if (account == NULL)
		throw Bank::InvalidAccountId();

	return (*account);
}

int Bank::CreateAccount(const unsigned int value)
{
	Account *newAccount = new Account();

	int accountId = newAccount->getId();
	_clientAccounts[accountId] = newAccount;

	AccountDeposit(accountId, value);

	return (accountId);
}

void Bank::DeleteAccount(const unsigned int id)
{
	Account *account = (*this)[id];
	if (account == NULL)
		throw Bank::InvalidAccountId();

	_clientAccounts.erase(id);
	delete account;
}

int Bank::getLiquidity() const
{
	return _liquidity;
}

void Bank::AddLiquidity(const unsigned int value)
{
	_liquidity += value;
}

void Bank::removeLiquidity(const unsigned int value)
{
	if (_liquidity < value)
		throw Bank::NotEnoughLiquidity();
	_liquidity -= value;
}

int Bank::AccountBalance(const unsigned int id)
{
	return getAccountRefById(id).getValue();
}

void Bank::AccountDeposit(const unsigned int id, const unsigned int value)
{
	int depositFee = value * _DEPOSIT_FEE_PERCENTAGE / 100;
	int valueAfterFee = value - (depositFee);

	getAccountRefById(id).addValue(valueAfterFee);
	_liquidity += depositFee;
}

void Bank::AccountWithdraw(const unsigned int id, const unsigned int value)
{
	if (getAccountRefById(id).getValue() < value)
		throw Bank::NotEnoughFunds();
	if (_liquidity < value)
		throw Bank::NotEnoughLiquidity();
	getAccountRefById(id).addValue(-value);
	_liquidity -= value;
}

void Bank::Loan(const unsigned int id, const unsigned int value)
{
	if (_liquidity < value)
		throw Bank::NotEnoughLiquidity();

	getAccountRefById(id).addValue(value);
	_liquidity -= value;
}

std::ostream &operator<<(std::ostream &p_os, const Bank &p_bank)
{
	p_os << "Bank informations : " << std::endl;
	p_os << "Liquidity : " << p_bank._liquidity << std::endl;
	for (std::map<unsigned int, Bank::Account *>::const_iterator it = p_bank._clientAccounts.begin(); it != p_bank._clientAccounts.end(); it++)
		p_os << (*it).second << std::endl;
	return (p_os);
}