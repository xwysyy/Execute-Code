#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> count;

        // Count occurrences of each number
        for (int num : a) {
            count[num]++;
        }

        int minValue = INT_MAX;
        bool found = false;

        // Check for minimum value that occurs at least three times
        for (const auto& entry : count) {
            if (entry.second >= 3) {
                found = true;
                if (entry.first < minValue) {
                    minValue = entry.first;
                }
            }
        }

        return found ? minValue : -1;
    }
};


#endif