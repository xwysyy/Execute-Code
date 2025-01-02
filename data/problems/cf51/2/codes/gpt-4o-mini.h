#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        std::vector<int> lds;  // This will store the Longest Decreasing Subsequence
        for (int i = 0; i < n; i++) {
            // We want the longest decreasing subsequence, so we will use a negative value
            // for binary search to find the position.
            int pos = std::lower_bound(lds.begin(), lds.end(), -a[i]) - lds.begin();
            if (pos < lds.size()) {
                lds[pos] = -a[i];
            } else {
                lds.push_back(-a[i]);
            }
        }
        // The remaining elements that need to be removed
        return n - lds.size();
    }
};


#endif