#include "account.h"
Account::Account():m_accNumber("XX"),m_accName("VVV"),m_balance(0.0)
{

}

Account::Account(std::string s1,std::string s2,double bal):m_accNumber(s1),m_accName(s2),m_balance(bal)
{

}
//Account(std::string s1,std::string):
Account::Account(const Account& ref):m_accNumber(ref.m_accNumber),m_accName(ref.m_accName),m_balance(ref.m_balance)
{

} 
void Account::debit(double amount)
{
    m_balance-=amount;
}
void Account::credit(double amount)
{
    m_balance+=amount;
}
double Account::getBalance() const
{
    return m_balance;
}
void Account::dispay() const
{
    std::cout << "Account_number: " << m_accNumber<<"\n"
            <<  "Account_name:"  << m_accName<<"\n"
            <<  "Balance: "  << m_balance<<"\n";
}

