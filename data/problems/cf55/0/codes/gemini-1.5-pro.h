#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        int ans = 0;
        vector<bool> vis(n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            if (p[i - 1] == i) continue;
            if (p[p[i - 1] - 1] == i) continue;
            ans++;
            vis[i] = true;
            vis[p[i - 1]] = true;
        }
        return ans;
    }
};


#endif