#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        // Find maximum and minimum in the array
        int max_val = *max_element(a.begin(), a.end());
        int min_val = *min_element(a.begin(), a.end());

        // Calculate maximum possible cost
        return max_val - min_val;
    }
};


#endif