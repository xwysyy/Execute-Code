#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int ans = n - 1;
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> b;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    b.push_back(a[j]);
                }
            }
            if (b.empty()) continue;
            bool ok = true;
            for (int j = 1; j < b.size(); ++j) {
                if (b[j] > b[j - 1]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = min(ans, n - (int)b.size());
            }
        }
        return ans;
    }
};


#endif