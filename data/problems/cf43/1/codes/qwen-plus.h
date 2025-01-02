#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Sort the array to find the median easily
        sort(a.begin(), a.end());
        
        // The maximum possible value that all elements can become is the median of the entire array
        return a[(n - 1) / 2];
    }
};


#endif