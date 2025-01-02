#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        // Initialize the min and max with opposite extremes
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        
        // Traverse the array to find the global minimum and maximum
        for (int i = 0; i < n; ++i) {
            if (a[i] < min_val)
                min_val = a[i];
            if (a[i] > max_val)
                max_val = a[i];
        }
        
        // The maximum possible cost is the range of the entire array
        return max_val - min_val;
    }
};


#endif