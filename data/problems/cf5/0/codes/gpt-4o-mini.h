#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> countMap;

        // Count the occurrences of each element
        for (int num : a) {
            countMap[num]++;
        }

        int result = INT_MAX;
        // Find the minimum value that appears at least three times
        for (const auto& entry : countMap) {
            if (entry.second >= 3) {
                result = min(result, entry.first);
            }
        }

        return (result == INT_MAX) ? -1 : result;
    }
};


#endif