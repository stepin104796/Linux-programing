#include<iostream>
#include "account.h"
#include "account.cpp"

int main()
{
    Account a1("sindhu","1233",123.45);
    a1.dispay();
    Account a2;
    a2.dispay();
    return 0;
}
