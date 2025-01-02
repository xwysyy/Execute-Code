#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        std::unordered_map<int, int> frequency;
        int disturbance = 0;
        
        // Calculate initial disturbance and frequency of each topic
        for (int i = 0; i < n; ++i) {
            frequency[a[i]]++;
            if (i < n - 1 && a[i] == a[i + 1]) {
                disturbance++;
            }
        }

        // Calculate maximum occurrences allowable under swap, i.e., roughly half
        int maxAllowed = (n + 1) / 2;
        
        // Find if any frequency is exceeding the allowable swaps
        for (const auto& entry : frequency) {
            if (entry.second > maxAllowed) {
                return disturbance - (entry.second - maxAllowed);
            }
        }
        
        // If no frequency exceeded, minimum disturbance realizable is 0
        return disturbance;
    }
};


#endif