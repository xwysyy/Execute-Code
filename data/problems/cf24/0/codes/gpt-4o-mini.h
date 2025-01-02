#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int min_elem = *min_element(a.begin(), a.end()); // Find the minimum element
        int max_elem = *max_element(a.begin(), a.end()); // Find the maximum element
        return max_elem - min_elem; // Calculate and return the maximum cost
    }
};


#endif