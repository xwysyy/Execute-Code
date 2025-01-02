#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) {
        vector<int> result(n);
        int currentMaxScore = 1;
        int maxLengthWithCurrentMaxScore = 0;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] > currentMaxScore) {
                currentMaxScore = a[i];
                maxLengthWithCurrentMaxScore = 1;
            } else if (a[i] == currentMaxScore) {
                maxLengthWithCurrentMaxScore++;
            }
            result[i] = maxLengthWithCurrentMaxScore;
        }
        
        return result;
    }
};


#endif