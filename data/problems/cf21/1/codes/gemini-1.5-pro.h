#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long max_beauty = -1e18; // Initialize with a very small value
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<int> subarray;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) {
                        subarray.push_back(a[k]);
                    }
                }
                if (subarray.size() >=2){
                    long long current_max = -1e18;
                    for(int k = 0; k < subarray.size() -1; ++k){
                        current_max = max(current_max, (long long)subarray[k] * subarray[k+1]);
                    }
                    max_beauty = max(max_beauty, current_max);
                }


            }
        }

        for (int i = 0; i < n - 1; ++i) {
            max_beauty = max(max_beauty, (long long)a[i] * a[i + 1]);
        }
        return max_beauty;
    }
};


#endif