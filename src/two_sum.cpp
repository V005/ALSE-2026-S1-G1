#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Cantidad de elementos: ";
    cin >> n;

    int nums[n];

    cout << "Ingrese los elementos:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Ingrese el target: ";
    cin >> target;

    bool encontrado = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                cout << "Indices: " << i << " y " << j << endl;
                encontrado = true;
                break;
            }
        }
        if (encontrado) break;
    }

    if (!encontrado) {
        cout << "No existe solucion." << endl;
    }

    return 0;
}