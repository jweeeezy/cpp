
#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return(_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals" << _nbWithdrawals << std::endl;
	return ;
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (_amount - withdrawal >= 0)
	{
		_amount -= withdrawal;
		return (true);
	}
	else
	{
		return (false);
	}
}

void	Account::makeDeposit( int deposit )
{
	_totalNbDeposits += 1;
	_totalAmount += deposit;

	_nbDeposits += 1;
	_amount += deposit;
	return ;
}


void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout 	<< "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals" << _totalNbWithdrawals << std::endl;
	return ;
}

void	Account::_displayTimestamp( void )
{
	std::time_t current_time;
	current_time = std::time(NULL);

	std::tm* local_time;
	local_time = std::localtime(&current_time);

	char buffer[20];

	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", local_time);
	std::cout << buffer;
	return ;
}

Account::Account(int initial_deposit)
{
	this->_totalAmount += initial_deposit;
	this->_nbAccounts += 1;
	this->_accountIndex = this->_nbAccounts - 1;
	this->_amount = initial_deposit;
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
	return ;
}

Account::Account( void )
{
	return ;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
	return ;
}