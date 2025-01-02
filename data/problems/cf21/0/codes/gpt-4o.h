#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, std::vector<int> &a) {
        if (n < 2) return 0;  // Though not needed due to constraints

        // Sort the array based on absolute values in descending order
        std::sort(a.begin(), a.end(), [](int x, int y) {
            return std::abs(x) > std::abs(y);
        });

        // Calculate maximum beauty from top two pairs
        long long maxBeauty = LLONG_MIN;  // Initialize with very small number
        for (int i = 1; i < n; ++i) {
            long long product = 1LL * a[i - 1] * a[i];  // 1LL ensures using 64-bit multiplication
            if (product > maxBeauty) {
                maxBeauty = product;
            }
        }
        
        return maxBeauty;
    }
};


#endif