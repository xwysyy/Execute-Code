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
            int original_n = n[i];
            while (true) {
                int to_remove = 0;
                for (int j = 0; j < k; ++j) {
                    if (a[j] <= remaining) {
                        ++to_remove;
                    } else {
                        break;
                    }
                }
                if (to_remove == 0) {
                    break;
                }
                remaining -= to_remove;
            }
            results.push_back(remaining);
        }
        return results;
    }
};


#endif