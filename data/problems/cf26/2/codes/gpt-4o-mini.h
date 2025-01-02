#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, int &m, int &k, int &x, int &y, vector<pair<int, int>> &a) {   
        // Compute Vika's parity
        int vikaParity = (x + y) % 2;

        // Check if all friends have the same parity
        for (int i = 0; i < k; i++) {
            int friendParity = (a[i].first + a[i].second) % 2;
            if (friendParity != vikaParity) {
                return "YES"; // Found at least one friend with different parity
            }
        }
        
        return "NO"; // All friends have the same parity
    }
};


#endif