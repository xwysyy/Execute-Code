#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long ans1 = 0, ans2 = 0;
        vector<int> c1, c2;

        int i = 0, j = 0;
        while (c1.size() < n) {
            c1.push_back(b[j++]);
        }
        
        i = 0, j = 0;
        while(c2.size() < n){
            c2.push_back(b[m - 1 - j++]);
        }

        for (int i = 0; i < n; i++) {
            ans1 += abs(a[i] - c1[i]);
            ans2 += abs(a[i] - c2[i]);
        }

        return max(ans1, ans2);
    }
};


#endif