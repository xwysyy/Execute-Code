#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        int numKept = 0;
        int currentMax = INT_MIN;

        for (int i = 0; i < n; ++i) {
            if (a[i] >= currentMax) {
                currentMax = a[i];
                numKept++;
            }
        }
        
        return n - numKept;
    }
};


#endif