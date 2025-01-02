#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {
        // Sort array to make it easier to process
        sort(a.begin(), a.end());
        
        // Alice removes k smallest elements by starting from k position
        int start = k;
        
        // Calculate sum of remaining elements
        int sum = 0;
        vector<int> remaining;
        for (int i = start; i < n; i++) {
            remaining.push_back(a[i]);
            sum += a[i];
        }
        
        // Sort remaining elements by absolute value in descending order
        // Bob will negate x largest numbers to minimize sum
        sort(remaining.begin(), remaining.end(), 
             [](int a, int b) { return abs(a) > abs(b); });
        
        // Bob negates up to x largest numbers
        for (int i = 0; i < min(x, (int)remaining.size()); i++) {
            if (remaining[i] > 0) {
                sum -= 2 * remaining[i];  // Subtract twice to account for negation
            }
        }
        
        return sum;
    }
};


#endif