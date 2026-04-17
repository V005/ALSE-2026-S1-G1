#include "AuctionSystem.h"

AuctionSystem::AuctionSystem() {}

void AuctionSystem::addBid(int userId, int itemId, int bidAmount) {
    //Si el usuario ya ofertó, el mapa sobreescribe el valor auto
    ofertasPorItem[itemId][userId] = bidAmount;
}

void AuctionSystem::updateBid(int userId, int itemId, int newAmount) {
    //Actualizar la oferta 
    ofertasPorItem[itemId][userId] = newAmount;
}

void AuctionSystem::removeBid(int userId, int itemId) {
    //Eliminar la entrada del usuario para ese ítem específico
    ofertasPorItem[itemId].erase(userId);
    
    //si el ítem ya no tiene ninguna oferta se quita del mapa principal
    if (ofertasPorItem[itemId].empty()) {
        ofertasPorItem.erase(itemId);
    }
}

int AuctionSystem::getHighestBidder(int itemId) {
    //si el ítem no existe en el registro no hay postores
    if (ofertasPorItem.find(itemId) == ofertasPorItem.end()) {
        return -1;
    }

    int ganadorId = -1;
    int ofertaMax = -1;

    //Recorrer todos los usuarios que ofertaron
    for (auto const& [usuario, monto] : ofertasPorItem[itemId]) {
        if (monto > ofertaMax) {
            ofertaMax = monto;
            ganadorId = usuario;
        } 
        else if (monto == ofertaMax) {
            //desempate: Si la oferta es igual, gana el ID de usuario más alto
            if (usuario > ganadorId) {
                ganadorId = usuario;
            }
        }
    }
    
    return ganadorId;
}