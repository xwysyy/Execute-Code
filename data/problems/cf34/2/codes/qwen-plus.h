#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {   
        // Sort the arrays a and b
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        // Two pointers to traverse from both ends of array b
        int left = 0;
        int right = m - 1;
        bool useLeft;
        long long maxDifference = 0;
        
        // For each element in a, choose either the smallest or largest remaining element in b
        for (int i = 0; i < n; ++i) {
            int diffLeft = abs(a[i] - b[left]);
            int diffRight = abs(a[i] - b[right]);
            
            // Choose the element that maximizes the difference
            if (diffLeft > diffRight) {
                useLeft = true;
            } else {
                useLeft = false;
            }
            
            // Add the maximum difference and move the pointer accordingly
            maxDifference += max(diffLeft, diffRight);
            if (useLeft) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxDifference;
    }
};


#endif