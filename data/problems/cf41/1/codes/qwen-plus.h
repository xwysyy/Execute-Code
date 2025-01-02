#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &k, int &q, vector<int> &a, vector<int> &n) {  
        vector<int> winners;
        for (int i = 0; i < q; ++i) {
            int remaining = n[i];
            bool changed;
            do {
                changed = false;
                for (int j = 0; j < k && remaining >= a[j]; ++j) {
                    if (remaining >= a[j]) {
                        remaining -= (remaining / a[j]);
                        changed = true;
                    }
                }
            } while (changed);
            winners.push_back(remaining);
        }
        return winners;
    }
};


#endif