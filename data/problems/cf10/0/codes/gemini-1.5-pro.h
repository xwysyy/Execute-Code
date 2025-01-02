#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, char &c, string &s) {
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                pos.push_back(i);
            }
        }
        int ans = 0;
        for (int start : pos) {
            int cur = 0;
            bool found = false;
            while (!found) {
                cur++;
                int next_pos = (start + cur) % n;
                if (s[next_pos] == 'g') {
                    found = true;
                }
                if (cur > 2 * n) break; 
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};


#endif