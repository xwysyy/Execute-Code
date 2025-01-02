#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        unordered_map<int, int> freq;
        
        // Count the frequency of each coin value
        for (int value : a) {
            freq[value]++;
        }
        
        // Determine the maximum frequency
        int max_pockets = 0;
        for (const auto& entry : freq) {
            max_pockets = max(max_pockets, entry.second);
        }
        
        return max_pockets;
    }
};


#endif