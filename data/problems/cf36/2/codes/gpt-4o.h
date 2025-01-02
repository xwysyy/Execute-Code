#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        std::unordered_map<int, int> frequencyMap;
        int maxFrequency = 0;

        for (int i = 0; i < n; ++i) {
            int adjustedValue = a[i] - i;
            frequencyMap[adjustedValue]++;
            maxFrequency = std::max(maxFrequency, frequencyMap[adjustedValue]);
        }

        return maxFrequency;
    }
};


#endif