#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {
        int maxLength = 0;
        int currentSum = 0;
        int start = 0;
        
        for (int end = 0; end < n; ++end) {
            currentSum += a[end];
            
            // While we're invalid either by the fruit count or divisibility, increment start
            while (currentSum > k || (end > start && h[end-1] % h[end] != 0)) {
                currentSum -= a[start];
                start++;
            }
            
            // If the current window is valid, update maxLength
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};


#endif