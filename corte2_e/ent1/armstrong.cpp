#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int num;
    cout << "Ingresa un número: ";
    cin >> num;

    int original = num;
    int digitos = 0;
    int sum = 0;

    //1. Separar los digitos y elevarlos
    int temp = num;
    while (temp != 0){  
        digitos++;
        temp = temp / 10; 
    }

    temp = num;
    while(temp != 0){
        int digito = temp % 10;            //separar con MOD
        sum = sum + pow(digito, digitos);  //sumar los digitos el resultado de la elevación
        temp = temp /10;
    }

    //2. Comparar con el original
    if (sum == original){
        cout << original << " es un número Armstrong" <<endl;
    } else {
        cout << original << " no es un número Armstrong" <<endl;

    }


    return 0;
}