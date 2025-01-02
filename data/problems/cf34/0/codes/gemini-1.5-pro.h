#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long ans = 0;
        int l = 0, r = m - 1;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[r]) {
                ans += b[r] - a[i];
                r--;
            } else if (a[i] > b[l]) {
                ans += a[i] - b[l];
                l++;
            } else {
                if (abs(a[i] - b[l]) > abs(a[i] - b[r])) {
                    ans += abs(a[i] - b[l]);
                    l++;
                } else {
                    ans += abs(a[i] - b[r]);
                    r--;
                }
            }
        }
        return ans;
    }
};


#endif