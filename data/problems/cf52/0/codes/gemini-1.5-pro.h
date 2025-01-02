#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<vector<int>> &a) {
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] < 0) {
                    int add = -a[i][j];
                    ans += add;
                    for (int k = 0; k <= n - 1 - i && k <= n - 1 - j; k++) {
                        a[i + k][j + k] += add;
                    }
                }
            }
        }
        return ans;
    }
};


#endif