#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {  
        vector<int> results;
        for (int i = 0; i < q; ++i) {
            int remaining = n[i];
            for (int j = 0; j < k; ++j) {
                if (a[j] > remaining) break;
                remaining = (remaining - 1) / k * k + min(a[j] - 1, remaining);
            }
            results.push_back(remaining);
        }
        return results;
    }
};


#endif