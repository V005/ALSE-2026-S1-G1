#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int best = 0;

        for (int i = 1; i < (int)prices.size(); i++) {
            minPrice = min(minPrice, prices[i]);
            best = max(best, prices[i] - minPrice);
        }
        return best;
    }
};

int main() {
    Solution sol;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Caso 1 (esperado 5 MAX): " << sol.maxProfit(prices1) << endl;

    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Caso 2 (esperado 0 MIN): " << sol.maxProfit(prices2) << endl;

    return 0;
}