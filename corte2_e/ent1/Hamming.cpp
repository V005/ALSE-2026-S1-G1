#include <iostream>
#include <string> //palabras o secuencias de letras se guardan en string


using namespace std;

int main() {
    string cadena1, cadena2;

    cout << "Ingrese la primera cadena de ADN: ";
    cin >> cadena1; 

    cout << "Ingrese la segunda cadena de ADN: ";
    cin >> cadena2;

    //length para recorrer cada letra 
    if (cadena1.length() != cadena2.length()) {
        cout << "Las secuencias tienen longitudes diferentes." << endl;
        return 1;
    }

    int distanciaHamming = 0;
    for (int i = 0; i < cadena1.length(); i++) {
        if (cadena1[i] != cadena2[i]) {
            distanciaHamming++;
        }
    }

    cout << "La distancia de Hamming calculada es: " << distanciaHamming << endl;

    return 0;
}