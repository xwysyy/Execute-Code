#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        unordered_map<int, int> prefixSumIndex;
        prefixSumIndex[0] = -1;
        int sum = 0;
        int beautifulSegments = 0;
        int lastEnd = -1;

        for (int i = 0; i < n; ++i) {
            sum += a[i];
            if (prefixSumIndex.find(sum) != prefixSumIndex.end()) {
                if (prefixSumIndex[sum] >= lastEnd) {
                    beautifulSegments++;
                    lastEnd = i;
                }
            }
            prefixSumIndex[sum] = i;
        }

        return beautifulSegments;
    }
};


#endif