#include "ATM.h"
#include <algorithm> //usar min()

ATM::ATM() {
    //cajero en cero
    for (int i = 0; i < 5; i++) {
        cantidadBilletes[i] = 0;
    }
}

void ATM::deposit(vector<int> banknotesCount) {
    for (int i = 0; i < 5; i++) {
        cantidadBilletes[i] += banknotesCount[i];
    }
}

vector<int> ATM::withdraw(int amount) {
    vector<int> aEntregar(5, 0);
    long long restante = amount;

    //Greedy: desde el billete más grande (índice 4 =500)
    for (int i = 4; i >= 0; i--) {
        if (restante >= valores[i]) {
            long long necesarios = restante / valores[i];
            //No se puede entregar más de lo que se tiene en el cajero
            long long aUsar = (necesarios < cantidadBilletes[i]) ? necesarios : cantidadBilletes[i];
            
            aEntregar[i] = (int)aUsar;
            restante -= (aUsar * valores[i]);
        }
    }

    //no monto exacto, devolver -1
    if (restante != 0) {
        return {-1};
    }

    //transacción hecha, restar los billetes del inventario
    for (int i = 0; i < 5; i++) {
        cantidadBilletes[i] -= aEntregar[i];
    }

    return aEntregar;
}