#include <iostream>
using namespace std;

class ParkingSystem {
public:

    int big;
    int medium;
    int small;

    ParkingSystem(int big, int medium, int small){
        //uso THIS para guardar el valor recibido en la variable de la clase y no tener que usar dos variables
        this->big = big;
        this->medium = medium;
        this->small = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(big > 0){
                big--; // restar 1 a la variable, se ocupa un espacio. FORMA CORTA
                return true;
            }
        }
        if(carType == 2){
            if(medium > 0){
                medium--; 
                return true;
            }
        }
         if(carType == 3){
            if(small > 0){
                small--; 
                return true;
            }
        }
        return false;
    }
};

//para poder ejecutar el programa en VS, simular el problema
int main(){
    ParkingSystem ps(1,1,0);
    cout << ps.addCar(1) <<endl;
    cout << ps.addCar(2) <<endl;
    cout << ps.addCar(3) <<endl;
    cout << ps.addCar(1) <<endl;

    return 0;

}