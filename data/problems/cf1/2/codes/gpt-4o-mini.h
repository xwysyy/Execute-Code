#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> frequency;
        
        // Count the frequency of each coin value
        for (int value : a) {
            frequency[value]++;
        }
        
        int max_count = 0;
        // Find the maximum frequency
        for (auto &pair : frequency) {
            max_count = max(max_count, pair.second);
        }

        // The result is the maximum frequency
        return max_count;
    }
};


#endif