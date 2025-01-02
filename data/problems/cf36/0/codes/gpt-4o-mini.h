#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<long long, int> frequency;
        
        // Count possible values after adding the permutation
        for (int i = 0; i < n; i++) {
            for (int add = 1; add <= n; add++) {
                frequency[a[i] + add]++;
            }
        }
        
        // Find the maximum frequency count
        int max_count = 0;
        for (const auto &entry : frequency) {
            if (entry.second > max_count) {
                max_count = entry.second;
            }
        }

        return max_count;
    }
};


#endif