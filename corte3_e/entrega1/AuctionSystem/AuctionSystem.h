#ifndef AUCTION_SYSTEM_H
#define AUCTION_SYSTEM_H

#include <string>
#include <unordered_map>

using namespace std;

class AuctionSystem {
private:
    //estructura de datos: itemId -> userId -> montoDeLaOferta
    unordered_map<int, unordered_map<int, int>> ofertasPorItem;

public:
    AuctionSystem();
    void addBid(int userId, int itemId, int bidAmount);
    void updateBid(int userId, int itemId, int newAmount);
    void removeBid(int userId, int itemId);
    int getHighestBidder(int itemId);
};

#endif