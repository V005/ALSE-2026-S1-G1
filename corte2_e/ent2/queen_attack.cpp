#include <iostream>
#include <cmath> //std::abs (valor absoluto)

using namespace std;

//Estructura para las coordenadas de la reina
struct Position {
    int row;
    int col;
};

class QueenAttack {
public:
    // Es una función estática la cual no necesita crear un objeto para usarla
    static bool canAttack(Position white, Position black) {
        //Misma fila
        if (white.row == black.row) return true;

        //Misma columna
        if (white.col == black.col) return true;

        //Misma diagonal
        //Si la distancia en filas es igual a la distancia en columnas, es diagonal
        int rowDiff = abs(white.row - black.row);
        int colDiff = abs(white.col - black.col);
        
        return rowDiff == colDiff;
    }
};

int main() {
    //Caso para prueba:
    Position white = {3, 2};
    Position black = {6, 5};

    cout << "--- Prueba de Ataque de Reinas ---" << endl;
    cout << "Reina Blanca en: {" << white.row << "," << white.col << "}" << endl;
    cout << "Reina Negra en:  {" << black.row << "," << black.col << "}" << endl;

    if (QueenAttack::canAttack(white, black)) {
        cout << "\nRESULTADO: ¡Se pueden atacar! (Están en diagonal)" << endl;
    } else {
        cout << "\nRESULTADO: No se pueden atacar." << endl;
    }

    return 0;
}