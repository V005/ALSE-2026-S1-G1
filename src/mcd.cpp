#include <iostream>
#include <cstdlib> //abs
using namespace std;
int mcd (int a, int b) {
    a = abs(a);
    b = abs(b);

    //si alguno es 0
    if(a == 0)return b;
    if(b == 0)return a;

    //Algoritmo Euclides
    while (b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;
    cout<<"Ingrese el primer número: ";
    cin>> a;
    cout<<"Ingrese el segundo número: ";
    cin>> b;

    cout<< "El MDC de " << a << " y " << b << " es: " <<mcd(a, b) << endl;
    return 0;
}