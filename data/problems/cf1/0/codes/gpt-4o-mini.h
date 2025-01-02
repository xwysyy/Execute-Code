#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> valueCount;
        
        // Count the frequency of each coin value
        for (int i = 0; i < n; i++) {
            valueCount[a[i]]++;
        }
        
        // The answer is the maximum frequency of any coin value
        int maxPockets = 0;
        for (const auto& pair : valueCount) {
            maxPockets = max(maxPockets, pair.second);
        }
        
        return maxPockets;
    }
};


#endif