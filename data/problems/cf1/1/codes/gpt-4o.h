#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        std::unordered_map<int, int> frequency;
        for (int coin : a) {
            frequency[coin]++;
        }
        
        int maxFrequency = 0;
        for (const auto& pair : frequency) {
            maxFrequency = std::max(maxFrequency, pair.second);
        }
        
        return maxFrequency;
    }
};


#endif