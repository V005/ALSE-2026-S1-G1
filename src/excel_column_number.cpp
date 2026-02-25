#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long ans = 0;

        for (char c : columnTitle) {
            int val = (c - 'A') + 1;   // A=1, B=2, ..., Z=26
            ans = ans * 26 + val;
        }
        return (int)ans;
    }
};

int main() {
    Solution sol;

    cout << "A -> " << sol.titleToNumber("A") << endl;
    cout << "AB -> " << sol.titleToNumber("AB") << endl;
    cout << "ZY -> " << sol.titleToNumber("ZY") << endl;

    return 0;
}