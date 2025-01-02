#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        unordered_map<int, int> freq;
        
        // Count the frequency of each element
        for (int i = 0; i < n; ++i) {
            freq[a[i]]++;
        }
        
        // Find the minimum value that appears at least three times
        int result = -1;
        for (const auto& pair : freq) {
            if (pair.second >= 3) {
                if (result == -1 || pair.first < result) {
                    result = pair.first;
                }
            }
        }
        
        return result;
    }
};


#endif