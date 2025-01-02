#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        int maxBlankSpace = 0;
        int currentBlankSpace = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                currentBlankSpace++;
            } else {
                if (currentBlankSpace > maxBlankSpace) {
                    maxBlankSpace = currentBlankSpace;
                }
                currentBlankSpace = 0;
            }
        }

        // Check at the end in case the longest blank space was at the end of the array
        if (currentBlankSpace > maxBlankSpace) {
            maxBlankSpace = currentBlankSpace;
        }

        return maxBlankSpace;
    }
};


#endif