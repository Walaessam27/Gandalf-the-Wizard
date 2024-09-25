#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int result(int totalW, vector<pair<int, int>>& ts) {
    vector<int> minT(totalW + 1, INT_MAX);
    minT[0] = 0;
    for (int currW = 1; currW <= totalW; ++currW) {
        for (const auto& t : ts) {
            int tW = t.first;
            int tV = t.second;
            if (currW >= tW && minT[currW - tW] != INT_MAX) {
                minT[currW] = min(minT[currW], minT[currW - tW] + tV);
            }
        }
    }
    return minT[totalW] == INT_MAX ? 0 : minT[totalW];
}

int main() {
    int chestW, numT;
    cin >> chestW >> numT;
    vector<pair<int, int>> ts(numT);
    for (int i = 0; i < numT; ++i) {
        int w, val;
        cin >> w >> val;
        ts[i] = {w, val};
    }
    int res = result(chestW, ts);
    cout << res << endl;
    return 0;
}
