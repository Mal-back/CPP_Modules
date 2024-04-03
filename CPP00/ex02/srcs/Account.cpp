/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: purmerinos <purmerinos@protonmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:30:52 by purmerinos        #+#    #+#             */
/*   Updated: 2024/04/03 13:30:56 by purmerinos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Account.hpp>
#include <ctime>
#include <iostream>
#include <ostream>

int Account::_nbAccounts;
int	Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account( int initial_deposit ) :_amount(initial_deposit) {
	_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< initial_deposit << ";created" << std::endl;
	_nbAccounts += 1;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	return ;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return(_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:"
		<< getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:"
		<< _amount << ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;	
	_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits += 1;
	this->_totalNbDeposits += 1;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;	
}

int		Account::checkAmount( void ) const
{
	return(_amount);
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";	
	if (checkAmount() < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (0);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	return (1);
}

void	Account::_displayTimestamp( void ) {
	time_t current_time;
	tm *current_time_ptr;
	char	date[20];
	char hours[20];

	time(&current_time);
	current_time_ptr = localtime(&current_time);
	std::strftime(date, 19, "%Y%m%d", current_time_ptr);
	std::strftime(hours, 19, "%H%M%S", current_time_ptr);
	std::cout << "[" << date << "_" << hours << "] ";

}
