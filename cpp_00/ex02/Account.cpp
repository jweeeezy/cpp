
#include "Account.hpp"
#include <iostream>			// needed for std::cout, std::endl
#include <ctime>			// needed for std::*time*

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return(Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return(Account::_totalNbWithdrawals);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
	return ;
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > 0)
	{
		_displayTimestamp();
		if (_amount - withdrawal >= 0)
		{
			_totalNbWithdrawals += 1;
			_totalAmount -= withdrawal;
			_nbWithdrawals += 1;
			std::cout 	<< "index:" << _accountIndex << ";"
						<< "p_amount:" << _amount << ";"
						<< "withdrawal:" << withdrawal << ";"
						<< "amount:" << _amount - withdrawal << ";"
						<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
			_amount -= withdrawal;
			return (true);
		}
		else
		{
			std::cout 	<< "index:" << _accountIndex << ";"
						<< "p_amount:" << _amount << ";"
						<< "withdrawal:" << "refused" << std::endl;
		}
	}
	return (false);
}

void	Account::makeDeposit( int deposit )
{
	if (deposit > 0)
	{
		_displayTimestamp();
		_totalNbDeposits += 1;
		_totalAmount += deposit;
		_nbDeposits += 1;
		std::cout 	<< "index:" << _accountIndex << ";"
					<< "p_amount:" << _amount << ";"
					<< "deposit:" << deposit << ";"
					<< "amount:" << _amount + deposit << ";"
					<< "nb_deposits:" << _nbDeposits << std::endl;
		_amount += deposit;
	}
	return ;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout 	<< "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals << std::endl;
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
	std::cout << buffer << " ";
	return ;
}

Account::Account(int initial_deposit)
{
	if (initial_deposit >= 0)
	{
		this->_totalAmount += initial_deposit;
		this->_nbAccounts += 1;
		this->_accountIndex = this->_nbAccounts - 1;
		this->_amount = initial_deposit;
		_displayTimestamp();
		std::cout 	<< "index:" << _accountIndex << ";"
					<< "amount:" << _amount << ";"
					<< "created" << std::endl;
	}
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

/* ************************************************************************** */
