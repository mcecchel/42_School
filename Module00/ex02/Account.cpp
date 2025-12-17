#include "Account.hpp"
#include <iostream>
#include <ctime>

// Inizializzo variabili static
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// Costruttore
Account::Account(int initial_deposit)
{
	// Imposto valori per questo account
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	// Aggiorna i totali globali (static)
	_nbAccounts++;
	_totalAmount += initial_deposit;
	// Stampo messaggio di conferma creazione
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

// Distruttore
Account::~Account(void)
{
	// Stampo messaggio di chiusura con stato finale
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

// Imposto i metodi Getter (Static) = restituisco valori delle var globali
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

// Display info globali degli account
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

// Gestione Deposit (depositare denaro)
void	Account::makeDeposit(int deposit)
{
	int	previous_amount = _amount;// Salvo valore precedente peima di aggiornare
	// Aggiorno contatore depositi personale
	_amount += deposit;
	_nbDeposits++;
	// Aggiorna totale denaro globale
	_totalAmount += deposit;
	_totalNbDeposits++;
	// Stampa messaggi
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << previous_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

// Gestione Withdrawal (prelevare denaro)
bool	Account::makeWithdrawal(int withdrawal)
{
	int	previous_amount = _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << previous_amount << ";";
	// Gestione caso se non ci sono abbastanza soldi sul conto
	if (withdrawal > _amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	// Altrimenti procede come il deposito e sottrae somma prelevata
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

// Check amount (controllare il saldo)
void	Account::displayStatus(void)const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

// Display Timestamp (vede essere in formato YYYYMMDD_HHMMSS)
void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	std::tm *localtime = std::localtime(&now);
	std::cout << "[";
	std::cout << (1900 + localtime->tm_year);
	if (localtime->tm_mon + 1 < 10)// NB: tm_mon va da 0 a 11 quindi va fatto +1
		std::cout << "0";
	std::cout << (localtime->tm_mon + 1);
	if (localtime->tm_mday < 10)
		std::cout << "0";
	std::cout << localtime->tm_mday;
	if (localtime->tm_hour < 10)
		std::cout << "0";
	std::cout << localtime->tm_hour;
	if (localtime->tm_min < 10)
		std::cout << "0";
	std::cout << localtime->tm_min;
	if (localtime->tm_sec < 10)
		std::cout << "0";
	std::cout << localtime->tm_sec;
	std::cout << "] ";
}
