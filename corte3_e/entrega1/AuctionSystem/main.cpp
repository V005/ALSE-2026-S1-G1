#include <iostream>
#include "AuctionSystem.h"

using namespace std;

int main() {
    AuctionSystem* subasta = new AuctionSystem();

    cout << "--- Simulacion de Sistema de Subastas ---" << endl;

    // Usuarios ofertan por el item 7
    subasta->addBid(1, 7, 5); //U1 ofrece
    subasta->addBid(2, 7, 6); //U2 ofrece 6
    cout << "Mejor postor item 7 (esperado 2): " << subasta->getHighestBidder(7) << endl;

    //U1 sube su apuesta
    subasta->updateBid(1, 7, 8); 
    cout << "Mejor postor item 7 tras update (esperado 1): " << subasta->getHighestBidder(7) << endl;

    //U2 se retira
    subasta->removeBid(2, 7);
    cout << "Mejor postor item 7 tras remover usuario 2 (esperado 1): " << subasta->getHighestBidder(7) << endl;

    //Item que no existe
    cout << "Mejor postor item 3 (esperado -1): " << subasta->getHighestBidder(3) << endl;

    delete subasta;
    return 0;
}