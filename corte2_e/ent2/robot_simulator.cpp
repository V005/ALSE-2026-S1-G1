#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Definir las direcciones
enum class Direction {
    NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3
};

//Clase del Robot
class Robot {
private:
    int x, y;
    Direction dir;

public:
    Robot(int x_start, int y_start, Direction start_dir) 
        : x(x_start), y(y_start), dir(start_dir) {}

    int getX() const { return x; }
    int getY() const { return y; }
    Direction getDirection() const { return dir; }

    void turnRight() {
        dir = static_cast<Direction>((static_cast<int>(dir) + 1) % 4);
    }

    void turnLeft() {
        dir = static_cast<Direction>((static_cast<int>(dir) + 3) % 4);
    }

    void advance() {
        if (dir == Direction::NORTH) y++;
        else if (dir == Direction::EAST)  x++;
        else if (dir == Direction::SOUTH) y--;
        else if (dir == Direction::WEST)  x--;
    }

    void executeInstructions(string instructions) {
        for (char i : instructions) {
            if (i == 'R') turnRight();
            else if (i == 'L') turnLeft();
            else if (i == 'A') advance();
        }
    }

    //función para imprimir el estado
    void printStatus() {
        string d;
        if (dir == Direction::NORTH) d = "North";
        else if (dir == Direction::EAST) d = "East";
        else if (dir == Direction::SOUTH) d = "South";
        else d = "West";
        cout << "Robot en {" << x << ", " << y << "} mirando al " << d << endl;
    }
};

// MAIN para compilar y poder probarlo
int main() {
   
    Robot myRobot(7, 3, Direction::NORTH);
    
    cout << "--- Inicio ---" << endl;
    myRobot.printStatus();
//RAALAL SON LAS POSICIONES DEL BOT SEGÚN LAS COORDENADAS 
    cout << "\nEjecutando instrucciones: RAALAL..." << endl;
    myRobot.executeInstructions("RAALAL");

    cout << "\n--- Resultado Final ---" << endl;
    myRobot.printStatus(); 
    //según las coordenas, me dirá la orientación

    return 0;
}