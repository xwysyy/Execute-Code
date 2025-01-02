#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            // Calculate the frequency of (a[i] - (i + 1)) % n to handle wrap-around
            int key = (a[i] - (i + 1) + n) % n;
            freq[key]++;
        }
        
        int maxCount = 0;
        for (auto &[key, value] : freq) {
            maxCount = max(maxCount, value);
        }

        return maxCount + 1;
    }
};


#endif