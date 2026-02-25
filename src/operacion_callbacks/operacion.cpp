#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// CALLBACKS

double suma(double a, double b) {
    return a + b;
}

double resta(double a, double b) {
    return a - b;
}

double multiplicacion(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    if (b == 0) {
        throw invalid_argument("Division por cero");
    }
    return a / b;
}

//FUNCION QUE RECIBE EL CALLBACK 

double operar(double a, double b, double (*func)(double, double)) {
    return func(a, b);
}



int main(int argc, char* argv[]) {

    // Cantidad de argumentos
    if (argc != 4) {
        cout << "Ha ingresado valores inadecuados para el programa\n";
        cout << "USO: ./ejecutable <num1> <operador> <num2>\n";
        return 1;
    }

    double num1, num2;
    string operador;

    // Para convertir argumentos a numeros
    try {
        num1 = stod(argv[1]);
        operador = argv[2];
        num2 = stod(argv[3]);
    } 
    catch (...) {
        cout << "Ha ingresado valores inadecuados para el programa\n";
        cout << "USO: ./ejecutable <num1> <operador> <num2>\n";
        return 1;
    }

    double resultado;

    // Ejecutar la operacion usando callbacks
    try {
        if (operador == "+") {
            resultado = operar(num1, num2, suma);
        }
        else if (operador == "-") {
            resultado = operar(num1, num2, resta);
        }
        else if (operador == "*" || operador == "x" || operador == "X") {
            resultado = operar(num1, num2, multiplicacion);
        }
        else if (operador == "/") {
            resultado = operar(num1, num2, division);
        }
        else {
            cout << "Operador invalido.\n";
            cout << "USO: ./ejecutable <num1> <operador> <num2>\n";
            return 1;
        }

        cout << "El resultado de la operacion es " << resultado << endl;
    }
    catch (...) {
        cout << "Error en la operacion (division por cero).\n";
        return 1;
    }

    return 0;
}