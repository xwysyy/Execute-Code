#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, char &c, string &s) {
        vector<int> next_green;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'g') {
                next_green.push_back(i);
            }
        }

        int max_wait = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                int wait = 0;
                bool found = false;
                for (int j = 0; j < next_green.size(); ++j) {
                    int diff = next_green[j] - i;
                    if (diff < 0) {
                        diff += n;
                    }
                    if (!found || diff < wait) {
                        wait = diff;
                        found = true;
                    }

                }
                max_wait = max(max_wait, wait);
            }
        }
        return max_wait;
    }
};


#endif