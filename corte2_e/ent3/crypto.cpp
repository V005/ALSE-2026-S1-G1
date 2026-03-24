#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    string texto, limpio = "";
    getline(cin, texto);

    // Quitar espacios para dejar solo las letras
    for (char c : texto) {
        if (c != ' ') limpio += c;
    }

    int L = limpio.length();
    int filas = round(sqrt(L));
    int columnas = ceil(sqrt(L));

    if (filas * columnas < L) filas = columnas;

    // Organizar en "cuadrícula" y leer por columnas para cifrar
    for (int j = 0; j < columnas; j++) {
        for (int i = 0; i < filas; i++) {
            int pos = i * columnas + j;
            if (pos < L) cout << limpio[pos];
        }
        cout << " "; // Separar los bloques de texto
    }
    cout << endl;

    return 0;
}