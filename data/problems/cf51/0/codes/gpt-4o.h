#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        if (n == 0) return 0;

        // Vector to store the longest non-decreasing subsequence
        std::vector<int> lnds;

        for (int i = 0; i < n; ++i) {
            // Using binary search to find the element's position in lnds
            auto it = std::upper_bound(lnds.begin(), lnds.end(), a[i]);

            // If element is larger than all elements in lnds or same as the end
            if (it == lnds.end()) {
                lnds.emplace_back(a[i]);
            } else {
                *it = a[i]; // If element can replace some existing element to maintain non-decreasing order
            }
        }

        // The result is total elements minus the length of the longest non-decreasing subsequence
        return n - static_cast<int>(lnds.size());
    }
};


#endif