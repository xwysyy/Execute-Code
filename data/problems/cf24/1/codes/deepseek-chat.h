#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 1) return 0; // If there's only one element, the cost is zero.
        int max_val = *max_element(a.begin(), a.end());
        int min_val = *min_element(a.begin(), a.end());
        return max_val - min_val;
    }
};


#endif