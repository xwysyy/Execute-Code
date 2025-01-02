#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n == 0) return 0;
        
        // Initialize dp arrays
        vector<int> dp_red(n, 0); // dp_red[i] represents the maximum score if a[i] is colored red
        vector<int> dp_not_red(n, 0); // dp_not_red[i] represents the maximum score if a[i] is not colored red
        
        // Base case
        dp_red[0] = a[0] + 1; // If the first element is red, score is a[0] + 1
        dp_not_red[0] = 0; // If the first element is not red, score is 0
        
        // Fill dp arrays
        for (int i = 1; i < n; ++i) {
            // If a[i] is colored red, a[i-1] cannot be red
            dp_red[i] = dp_not_red[i-1] + a[i] + 1;
            
            // If a[i] is not colored red, the previous element can be either red or not red
            dp_not_red[i] = max(dp_red[i-1], dp_not_red[i-1]);
        }
        
        // The maximum score is the maximum of the last element being red or not red
        return max(dp_red[n-1], dp_not_red[n-1]);
    }
};


#endif