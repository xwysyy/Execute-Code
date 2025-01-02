#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 0) return 0;
        
        vector<int> longestNonIncreasingSubseq;
        
        for (int i = 0; i < n; ++i) {
            if (longestNonIncreasingSubseq.empty() || longestNonIncreasingSubseq.back() >= a[i]) {
                longestNonIncreasingSubseq.push_back(a[i]);
            } else {
                // Find the position to replace
                auto pos = upper_bound(longestNonIncreasingSubseq.begin(), longestNonIncreasingSubseq.end(), a[i], greater<int>());
                *pos = a[i];
            }
        }
        
        // The length of the longest non-increasing subsequence
        int longestLength = longestNonIncreasingSubseq.size();
        
        // The minimum number of elements to remove
        return n - longestLength;
    }
};


#endif