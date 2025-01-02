#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a) {
        map<int, int> counts;
        for (int x : a) {
            counts[x]++;
        }

        int max_count = 0;
        for (auto const& [key, val] : counts) {
            max_count = max(max_count, val);
        }

        if (n == 1) return 1;

        int ans = 0;
        for (int target = 2; target <= 2 * n; ++target) {
            int current_count = 0;
            for (int i = 0; i < n; ++i) {
                int needed = target - a[i];
                if (needed >= 1 && needed <= n) {
                    current_count++;
                }
            }
            ans = max(ans, current_count);

        }
         return min(n,max(max_count, ans));
    }
};


#endif