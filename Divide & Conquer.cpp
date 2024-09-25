#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int result(int a, vector<pair<int, int>>& ms, unordered_map<int, int>& arry) {
    if (a == 0) return 0;
    if (arry.find(a) != arry.end()) return arry[a];
    int minval = INT_MAX;
    for (const auto& m : ms) {
        int matW = m.first;
        int matV = m.second;
        if (a >= matW) {
            int res = result(a - matW, ms, arry);
            if (res != INT_MAX) {
                minval = min(minval, res + matV);
            }
        }
    }
    arry[a] = minval;
    return minval;
}

int main() {
    int allA, numM;
    cin >> allA >> numM;
    vector<pair<int, int>> ms(numM);
    for (int i = 0; i < numM; ++i) {
        int w, val;
        cin >> w >> val;
        ms[i] = { w, val };
    }
    unordered_map<int, int> arry;
    int finalres = result(allA, ms, arry);
    if (finalres == INT_MAX) {
        finalres = 0;
    }
    cout << finalres << endl;
    return 0;
}
