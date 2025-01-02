#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) {
        vector<int> result(n);
        int maxScore = 1;
        int maxLength = 0;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] >= maxScore) {
                maxLength++;
                maxScore = a[i];
            } else {
                maxScore = 1;
                maxLength = 1;
            }
            result[i] = maxLength;
        }
        
        // Adjust the result to ensure it's non-decreasing and correctly reflects the maximum length subsequence with the highest score
        for (int i = 1; i < n; ++i) {
            result[i] = max(result[i], result[i - 1]);
        }
        
        return result;
    }
};


#endif