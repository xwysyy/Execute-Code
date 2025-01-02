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
        int startPos = k;
        
        // Calculate remaining elements after Alice's move
        vector<int> remaining;
        for(int i = startPos; i < n; i++) {
            remaining.push_back(a[i]);
        }
        
        // Sort remaining elements in descending order for Bob's move
        sort(remaining.begin(), remaining.end(), greater<int>());
        
        // Bob multiplies x largest numbers by -1
        for(int i = 0; i < min(x, (int)remaining.size()); i++) {
            remaining[i] = -remaining[i];
        }
        
        // Calculate final sum
        int sum = 0;
        for(int num : remaining) {
            sum += num;
        }
        
        return sum;
    }
};


#endif