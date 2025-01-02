#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        int ans = n;
        for (char c1 = 'a'; c1 <= 'z'; c1++) {
            for (char c2 = 'a'; c2 <= 'z'; c2++) {
                int cur = 0;
                for (int i = 0; i < n; i++) {
                    if (i % 2 == 0) {
                        if (s[i] != c1) cur++;
                    } else {
                        if (s[i] != c2) cur++;
                    }
                }
                ans = min(ans, cur);
            }
        }
        if (n % 2 != 0) {
            for (char c1 = 'a'; c1 <= 'z'; c1++) {
                for (char c2 = 'a'; c2 <= 'z'; c2++) {
                    for (int i = 0; i < n; i++) {
                        int cur = 1;
                        string t = "";
                        for(int j = 0; j < n; ++j) {
                            if(i != j) t += s[j];
                        }
                        for (int j = 0; j < n - 1; j++) {
                            if (j % 2 == 0) {
                                if (t[j] != c1) cur++;
                            } else {
                                if (t[j] != c2) cur++;
                            }
                        }
                        ans = min(ans, cur);
                    }
                }
            }
        }

        return ans;
    }
};


#endif