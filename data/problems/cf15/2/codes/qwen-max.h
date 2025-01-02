#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) {
        vector<int> result(n, 1);
        int maxScore = 1;
        int maxLen = 1;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] > 1) {
                int currentScore = 1;
                int currentLen = 1;
                for (int j = i; j >= 0 && currentScore * a[j] >= maxScore; --j) {
                    currentScore *= a[j];
                    currentLen++;
                }
                currentLen--;
                if (currentScore > maxScore) {
                    maxScore = currentScore;
                    maxLen = currentLen;
                }
            }
            result[i] = maxLen;
        }
        
        return result;
    }
};

#endif