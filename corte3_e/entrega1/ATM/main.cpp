#include <iostream>
#include <vector>
#include "ATM.h"

using namespace std;

void imprimirResultado(vector<int> resultado) {
    if (resultado.size() == 1 && resultado[0] == -1) {
        cout << "[-1] (Retiro rechazado)" << endl;
    } else {
        cout << "[";
        for (int i = 0; i < 5; i++) {
            cout << resultado[i] << (i < 4 ? "," : "");
        }
        cout << "]" << endl;
    }
}

int main() {
    ATM* miCajero = new ATM();

    cout << "--- Simulacion de Cajero ATM ---" << endl;

    //Depositar: 1 de 100, 2 de 200, 1 de 500
    cout << "Depositando: [0,0,1,2,1]..." << endl;
    miCajero->deposit({0, 0, 1, 2, 1});

    //Retirar 600
    cout << "Retirando 600: ";
    imprimirResultado(miCajero->withdraw(600)); // Esperado: [0,0,1,0,1]

    // 3.Depositar
    cout << "Depositando mas: [0,1,0,1,1]..." << endl;
    miCajero->deposit({0, 1, 0, 1, 1});

    // 4. Retirar 600 (Debería fallar)
    cout << "Retirando 600: ";
    imprimirResultado(miCajero->withdraw(600)); //esperado: [-1]

    delete miCajero;
    return 0;
}