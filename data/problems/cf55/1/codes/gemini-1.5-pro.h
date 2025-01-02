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
            if (!vis[i]) {
                if (p[i - 1] == i) {
                    vis[i] = true;
                } else {
                    int j = p[i - 1];
                    if (p[j - 1] == i) {
                        vis[i] = vis[j] = true;
                    } else {
                        ans++;
                        vis[i] = vis[j] = true;
                        int k = p[j-1];
                        while(!vis[k]){
                            vis[k] = true;
                            k = p[k-1];
                        }
                    }
                }
            }
        }
        return ans;
    }
};


#endif