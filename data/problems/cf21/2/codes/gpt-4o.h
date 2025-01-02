#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, std::vector<int> &a) {
        // Sorting the array
        std::sort(a.begin(), a.end());
        
        // Calculate possible maximum products
        long long maxProductPositive = static_cast<long long>(a[n-1]) * a[n-2]; // Two largest positive
        long long maxProductNegative = static_cast<long long>(a[0]) * a[1];     // Two smallest (most negative)
        
        // Return the maximum of these two products
        return std::max(maxProductPositive, maxProductNegative);
    }
};


#endif