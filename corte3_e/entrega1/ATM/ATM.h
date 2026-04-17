#ifndef ATM_H
#define ATM_H

#include <vector>

using namespace std;

class ATM {
private:
    //Q de billetes de: $20, $50, $100, $200, $500
    long long cantidadBilletes[5];
    //se deben fijar valores de cada billete según su posición
    int valores[5] = {20, 50, 100, 200, 500};

public:
    ATM();
    void deposit(vector<int> banknotesCount);
    vector<int> withdraw(int amount);
};

#endif