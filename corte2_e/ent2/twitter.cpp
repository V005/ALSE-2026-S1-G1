#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <iostream>

using namespace std;

class Twitter {
private:
    // ESTRUCT: guardar un tweet con su tiempo de creación
    struct Tweet {
        int id;
        int time;
    };

    // Mapa de ID_Usuario, ID de seguidos
    unordered_map<int, unordered_set<int>> following;
    
    // Mapa de ID_Usuario, lista de sus tweets
    unordered_map<int, vector<Tweet>> tweets;
    
    // Contador global para simular el paso del tiempo
    int timestamp;

public:
    Twitter() {
        timestamp = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // Agregar el tweet a la lista del usuario con el tiempo actual
        tweets[userId].push_back({tweetId, timestamp++});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Priority Queue (Min-Heap) para mantener solo los 10 más recientes y el heap guardará: {tiempo, tweetId}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // 1. Agregar los tweets del propio usuario
        if (tweets.count(userId)) {
            for (const auto& t : tweets[userId]) {
                minHeap.push({t.time, t.id});
                if (minHeap.size() > 10) minHeap.pop(); // Si hay más de 10, se saca el más antiguo
            }
        }

        // 2. Agregar los tweets de la persona a la que sigue
        if (following.count(userId)) {
            for (int followeeId : following[userId]) {
                if (tweets.count(followeeId)) {
                    for (const auto& t : tweets[followeeId]) {
                        minHeap.push({t.time, t.id});
                        if (minHeap.size() > 10) minHeap.pop();
                    }
                }
            }
        }

        // 3. Extraer los IDs del heap (del menos reciente al más reciente)
        vector<int> res;
        while (!minHeap.empty()) {
            res.insert(res.begin(), minHeap.top().second); // Insertamos al inicio para invertir orden
            minHeap.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        // Como un usuario no debería seguirse así mismo: 
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        // Para borrar al usuario de la lista de seguidos
        if (following.count(followerId)) {
            following[followerId].erase(followeeId);
        }
    }
};

//MAIN PARA COMPILAR
int main() {
    Twitter* obj = new Twitter();
    
    cout << "--- Iniciando prueba de Twitter ---" << endl;
    
    // Usuario 1 publica un tweet
    obj->postTweet(1, 101);
    cout << "Usuario 1 publico tweet 101" << endl;
    
    // Usuario 1 sigue al usuario 2
    obj->follow(1, 2);
    
    // Usuario 2 publica un tweet
    obj->postTweet(2, 202);
    cout << "Usuario 2 publico tweet 202" << endl;
    
    // Obtener feed del usuario 1
    vector<int> feed = obj->getNewsFeed(1);
    cout << "Feed del Usuario 1: ";
    for (int id : feed) cout << id << " ";
    cout << endl;

    delete obj;
    return 0;
}