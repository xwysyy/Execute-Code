#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Sort the array to easily find the median
        sort(a.begin(), a.end());
        
        // Find the median position for an array of size n
        int medianPosition = (n - 1) / 2;
        
        // Return the maximum possible value of uniform sequence which is the maximum
        // median we can choose from the array
        return a[medianPosition];
    }
};


#endif