#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        // Base case when the array has only one element
        if (n <= 1) return 0;
        
        // Initialize min and max with the first element of the array
        int minElem = a[0];
        int maxElem = a[0];
        
        // Iterate over the array to find the minimum and maximum elements
        for (int i = 1; i < n; i++) {
            if (a[i] < minElem) minElem = a[i];
            if (a[i] > maxElem) maxElem = a[i];
        }
        
        // Calculate the max cost which is the difference between max and min elements
        int maxCost = maxElem - minElem;
        return maxCost;
    }
};


#endif