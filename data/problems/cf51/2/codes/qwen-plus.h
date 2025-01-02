#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        int lisEndingHere = 1;
        int maxLis = 1;

        for (int i = 1; i < n; ++i) {
            if (a[i] <= a[i - 1]) {
                lisEndingHere++;
                maxLis = max(maxLis, lisEndingHere);
            } else {
                lisEndingHere = 1;
            }
        }

        // The minimum number of deletions required to make the array vulnerable
        return n - maxLis;
    }
};


#endif