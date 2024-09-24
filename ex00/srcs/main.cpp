#include "Bank.hpp"
#include <cassert>

#define DEPOSIT_FEE_PERCENTAGE 5

template <typename T>
void assertEqual(T got, T expected)
{
	if (got != expected)
	{
		std::cout << "--- expected: \"" << expected << "\" but got: \"" << got << "\"" << std::endl;
	}
	assert(got == expected);
}

void failTest(const char *msg)
{
	std::cout << "[failTest] " << msg << std::endl;
	assert(false);
}

void depositFeeApplicationTest()
{
	std::cout << "[depositFeeApplicationTest]" << std::endl;

	int initialLiquidity = 1000;
	Bank bank = Bank(initialLiquidity);

	int initialDeposit = 100;
	int accountAID = bank.CreateAccount(initialDeposit);

	assertEqual(bank.AccountBalance(accountAID), 95); // initial deposit - deposit fee (100 * 5%)
	assertEqual(bank.getLiquidity(), 1005);			  // initial liquidity + deposit fee (100 * 5%)

	std::cout << "[depositFeeApplicationTest end]" << std::endl
			  << std::endl;
}

void succesfullWithdrawTest()
{
	std::cout << "[succesfullWithdrawTest]" << std::endl;

	int initialLiquidity = 1000;
	Bank bank = Bank(initialLiquidity);

	int initialDeposit = 100;
	int accountAID = bank.CreateAccount(initialDeposit);

	int withdrawAmount = 50;
	bank.AccountWithdraw(accountAID, withdrawAmount);

	assertEqual(bank.AccountBalance(accountAID), 45); // initial deposit - deposit fee (100 * 5%) - withdraw amount
	assertEqual(bank.getLiquidity(), 955);			  // initial liquidity + deposit fee (100 * 5%) - withdraw amount

	std::cout << "[succesfullWithdrawTest end]" << std::endl
			  << std::endl;
}

void unsuccesfullWithdrawTest()
{
	std::cout << "[unsuccesfullWithdrawTest]" << std::endl;

	int initialLiquidity = 1000;
	Bank bank = Bank(initialLiquidity);

	int initialDeposit = 100;
	int accountAID = bank.CreateAccount(initialDeposit);

	try
	{
		int withdrawAmount = 150;
		bank.AccountWithdraw(accountAID, withdrawAmount); // should throw NotEnoughFunds
		failTest("Withdraw amount is greater than account balance");
	}
	catch (const Bank::NotEnoughFunds &e)
	{
	}

	std::cout << "[unsuccesfullWithdrawTest end]" << std::endl
			  << std::endl;
}

void succesfullLoanTest()
{
	std::cout << "[succesfullLoanTest]" << std::endl;

	int initialLiquidity = 1000;
	Bank bank = Bank(initialLiquidity);

	int initialDeposit = 100;
	int accountAID = bank.CreateAccount(initialDeposit);

	int loanAmount = 50;
	bank.Loan(accountAID, loanAmount);

	assertEqual(bank.AccountBalance(accountAID), 145); // initial deposit - deposit fee (100 * 5%) + loan amount
	assertEqual(bank.getLiquidity(), 955);			   // initial liquidity + deposit fee (100 * 5%) - loan amount

	std::cout << "[succesfullLoanTest end]" << std::endl
			  << std::endl;
}

void unsuccesfullLoanTest()
{
	std::cout << "[unsuccesfullLoanTest]" << std::endl;

	int initialLiquidity = 1000;
	Bank bank = Bank(initialLiquidity);

	int initialDeposit = 100;
	int accountAID = bank.CreateAccount(initialDeposit);

	int loanAmount = 1500;
	try
	{
		bank.Loan(accountAID, loanAmount); // should throw NotEnoughLiquidity
		failTest("Loan amount is greater than bank liquidity");
	}
	catch (Bank::NotEnoughLiquidity &e)
	{
	}

	std::cout << "[unsuccesfullLoanTest end]" << std::endl;
}

int main()
{
	depositFeeApplicationTest();
	succesfullWithdrawTest();
	unsuccesfullWithdrawTest();
	succesfullLoanTest();
	unsuccesfullLoanTest();

	return 0;
}