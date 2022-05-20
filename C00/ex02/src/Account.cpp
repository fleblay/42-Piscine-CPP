#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout	<< "accounts:" << Account::_nbAccounts << ";"
				<< "total:" << Account::_totalAmount << ";"
				<< "deposits:" << Account::_totalNbDeposits << ";"
				<< "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
	return ;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;

	this->_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "created" << std::endl;
	return ;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "closed" << std::endl;
	return ;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;

	this->_totalAmount += deposit;
	this->_totalNbDeposits++;

	this->_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << this->_amount << ";"
				<< "nb_deposits:" << this->_nbDeposits
				<< std::endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount = this->_amount;

	this->_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "p_amount:" << p_amount << ";"
				<< "withdrawal:";
	if (this->_amount >= withdrawal)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;

		this->_totalAmount -= withdrawal;
		this->_totalNbWithdrawals++;

		std::cout	<< withdrawal << ";"
					<< "amount:" << this->_amount << ";"
					<< "nb_withdrawals:" << this->_nbWithdrawals
					<< std::endl;
		return (1);
	}
	else
	{
		std::cout	<< "refused"
					<< std::endl;
		return (0);

	}
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";"
				<< "amount:" << this->_amount << ";"
				<< "deposits:" << this->_nbDeposits << ";"
				<< "withdrawals:" << this->_nbWithdrawals
				<< std::endl;
	return ;

}

void Account::_displayTimestamp(void)
{
	std::time_t	raw_time = std::time(NULL);
	struct tm	*local_time = localtime(&raw_time);

	std::cout	<< "["
				<< local_time->tm_year + 1900
				<< std::setfill('0') << std::setw(2)
				<< local_time->tm_mon + 1
				<< std::setfill('0') << std::setw(2)
				<< local_time->tm_mday
				<< "_"
				<< std::setfill('0') << std::setw(2)
				<< local_time->tm_hour
				<< std::setfill('0') << std::setw(2)
				<< local_time->tm_min
				<< std::setfill('0') << std::setw(2)
				<< local_time->tm_sec
				<< "] ";
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
