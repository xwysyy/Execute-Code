#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Sort the array
        sort(a.begin(), a.end());
        // The maximum possible value at the end is the second largest element
        return a[n - 2]; // Return the second last element as the array is 0-indexed
    }
};


#endif