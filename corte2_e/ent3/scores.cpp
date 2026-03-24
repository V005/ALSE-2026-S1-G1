#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, consultas;
    // Leer cantidad de exámenes y cuántas preguntas haré
    if (!(cin >> n >> consultas)) return 0;

    vector<int> puntajes(n);
    vector<long long> prefijos(n + 1, 0);

    // Llenar el arreglo y calcular las sumas acumuladas (Prefijos)
    for (int i = 0; i < n; i++) {
        cin >> puntajes[i];
        prefijos[i + 1] = prefijos[i] + puntajes[i];
    }

    // Responder cada consulta en tiempo récord
    for (int i = 0; i < consultas; i++) {
        int izq, der;
        cin >> izq >> der;
        // Restar el acumulado para sacar el total del rango
        cout << "Suma del rango: " << prefijos[der] - prefijos[izq - 1] << endl;
    }

    return 0;
}