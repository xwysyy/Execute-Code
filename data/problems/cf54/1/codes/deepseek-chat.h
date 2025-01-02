#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        int prefixSum = 0;
        int result = 0;
        
        for (int i = 0; i < n; ++i) {
            prefixSum += a[i];
            if (prefixSumCount.find(prefixSum) != prefixSumCount.end()) {
                result += prefixSumCount[prefixSum];
                prefixSumCount.clear();
                prefixSumCount[prefixSum] = 1;
            } else {
                prefixSumCount[prefixSum]++;
            }
        }
        
        return result;
    }
};


#endif