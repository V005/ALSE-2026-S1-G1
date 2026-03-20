#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Spreadsheet {
private:
    //Para guardar los valores en un mapa: "A1" que insdique el valor
    unordered_map<string, int> sheet;

    //Función auxiliar para saber si un string es un número o una celda
    int parseToken(string s) {
        if (s.empty()) return 0;
        
        // Si el primer carácter es una letra, es  una celda
        if (isalpha(s[0])) {
            return sheet.count(s) ? sheet[s] : 0;
        } 
        //De lo contrario es un número
        else {
            try {
                return stoi(s);
            } catch (...) {
                return 0; // Manejo básico por si el string no es un número válido
            }
        }
    }

public:
    Spreadsheet(int rows) {
        //No necesitamos inicializar todo a 0 explícitamente si usamos un mapa, 
        //ya que cualquier celda no encontrada devolverá 0 por lógica.
    }
    
    void setCell(string cell, int value) {
        sheet[cell] = value;
    }
    
    void resetCell(string cell) {
        sheet[cell] = 0;
    }
    
    int getValue(string formula) {
        if (formula.empty()) return 0;

        // Caso 1: Es una celda directa como A1 o un número
        if (formula[0] != '=') {
            return parseToken(formula);
        }

        // Caso 2: Es una fórmula como =A1+B2 
        string expression = formula.substr(1);
        
        //Buscar la posición del '+'
        size_t plusPos = expression.find('+');
        
        if (plusPos == string::npos) {
            // Si no hay '+', intentamos parsear lo que hay después del '='
            return parseToken(expression);
        }

        //Para separar los dos operandos
        string first = expression.substr(0, plusPos);
        string second = expression.substr(plusPos + 1);
        
        return parseToken(first) + parseToken(second);
    }
};

// PARA COMPILAR
int main() {
    // Se inicializa una hoja con 10 filas 
    Spreadsheet mySheet(10);

    cout << "--- Iniciando prueba de Spreadsheet ---" << endl;

    //valores a las celdas
    mySheet.setCell("A1", 15);
    mySheet.setCell("B2", 25);
    cout << "Celda A1 establecida en 15" << endl;
    cout << "Celda B2 establecida en 25" << endl;

    // Prueba 1: Valor directo
    cout << "Valor de A1: " << mySheet.getValue("A1") << " (Esperado: 15)" << endl;

    // Prueba 2: Fórmula de suma
    int suma = mySheet.getValue("=A1+B2");
    cout << "Resultado de =A1+B2: " << suma << " (Esperado: 40)" << endl;

    // Prueba 3: Suma con número constante
    int sumaConst = mySheet.getValue("=A1+10");
    cout << "Resultado de =A1+10: " << sumaConst << " (Esperado: 25)" << endl;

    return 0;
}