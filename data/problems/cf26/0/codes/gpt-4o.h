#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {
        // Determine Vika's coordinate parity
        int vika_parity = (x + y) % 2;
        
        // For each friend, check their coordinate parity
        for (int i = 0; i < k; ++i) {
            int friend_parity = (a[i].first + a[i].second) % 2;
            // If there is a parity mismatch, Vika can evade
            if (friend_parity != vika_parity) {
                return "YES"; // Different parity means she can evade
            }
        }
        // All friends have the same parity as Vika, she cannot evade indefinitely
        return "NO";
    }
};


#endif