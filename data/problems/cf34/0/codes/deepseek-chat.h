#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, std::vector<int> &a, std::vector<int> &b) {
        // Sort array a in ascending order
        std::sort(a.begin(), a.end());
        // Sort array b in descending order
        std::sort(b.begin(), b.end(), std::greater<int>());
        
        long long maxDifference = 0;
        for (int i = 0; i < n; ++i) {
            // Calculate the absolute difference between the ith smallest element in a
            // and the ith largest element in b
            maxDifference += std::abs(a[i] - b[i]);
        }
        
        return maxDifference;
    }
};


#endif