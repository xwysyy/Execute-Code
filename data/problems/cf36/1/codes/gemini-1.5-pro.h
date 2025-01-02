#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        map<int, int> counts;
        for (int x : a) {
            counts[x]++;
        }

        int max_count = 0;
        for (int target = n + 1; target <= 2 * n; ++target) {
            int current_count = 0;
            for (int x : a) {
                if (target - x >= 1 && target - x <= n) {
                    current_count++;
                }
            }
            max_count = max(max_count, current_count);
        }
        
        return max_count;
    }
};


#endif