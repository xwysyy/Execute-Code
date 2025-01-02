#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long max_beauty = -2e18; // Initialize with a very small value
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<int> subarray;
                subarray.push_back(a[i]);
                for (int k = i + 1; k <= j; ++k) {
                    subarray.push_back(a[k]);
                }
                if (subarray.size() >= 2) {
                    long long current_max_beauty = -2e18;
                    for (int k = 0; k < subarray.size() - 1; ++k) {
                        current_max_beauty = max(current_max_beauty, (long long)subarray[k] * subarray[k + 1]);
                    }
                    max_beauty = max(max_beauty, current_max_beauty);
                }
            }
        }
        
        
        return max_beauty;
    }
};


#endif