#include <iostream>
using namespace std;

int main() {
    const int N = 10;
    int arr[N];

    cout << "Ingrese 10 numeros para el arreglo:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Elemento " << (i + 1) << ": ";
        cin >> arr[i];
    }

    int buscado;
    cout << "Ingrese el numero a buscar: ";
    cin >> buscado;

    bool encontrado = false;
    int posicion = -1;

    for (int i = 0; i < N; i++) {
        if (arr[i] == buscado) {
            encontrado = true;
            posicion = i; // primera posición donde aparece
            break;
        }
    }

    if (encontrado) {
        cout << "El numero " << buscado << " SI esta en el arreglo. "
             << "Posicion (indice) = " << posicion << endl;
    } else {
        cout << "El numero " << buscado << " NO esta en el arreglo." << endl;
    }

    return 0;
}