#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Find the maximum and minimum elements in the array
        int maxElement = *max_element(a.begin(), a.end());
        int minElement = *min_element(a.begin(), a.end());
        
        // Return the difference which is the maximum possible cost
        return maxElement - minElement;
    }
};


#endif