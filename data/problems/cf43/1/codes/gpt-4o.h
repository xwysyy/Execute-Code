#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        // Sort the array
        std::sort(a.begin(), a.end()); 
        
        // The median of the sorted array in zero-indexed is at position (n / 2)
        return a[(n - 1) / 2]; // This will give us the maximum possible number
    }
};


#endif