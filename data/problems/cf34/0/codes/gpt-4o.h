#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, std::vector<int> &a, std::vector<int> &b) {
        // Sort both arrays a and b
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        
        long long maxDifference = 0;
        
        // Get the n largest elements from the sorted b
        std::vector<int> largestNFromB(b.end() - n, b.end());
        
        // Compute the max possible difference
        for (int i = 0; i < n; ++i) {
            maxDifference += std::abs(a[i] - largestNFromB[n - 1 - i]);
        }
        
        return maxDifference;
    }
};


#endif