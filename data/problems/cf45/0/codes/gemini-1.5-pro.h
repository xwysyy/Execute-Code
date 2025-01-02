#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {   
        sort(a.begin(), a.end());
        long long ans = 0;
        long long sum = 0;
        int l = 0;
        for (int r = 0; r < n; r++) {
            sum += a[r];
            while (l <= r && (a[r] - a[l] > 1 || sum > m)) {
                sum -= a[l];
                l++;
            }
            if (sum <= m) {
                ans = max(ans, sum);
            }
        }
        return ans;
    }
};


#endif