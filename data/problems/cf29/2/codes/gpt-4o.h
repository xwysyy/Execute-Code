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
            
            // Move the start pointer to satisfy both conditions:
            // 1. Whenever previous height division condition breaks.
            // 2. Current sum exceeds k.
            while (start < end && (!isDivisible(h[end-1], h[end]) || currentSum > k)) {
                currentSum -= a[start];
                start++;
            }
            
            // Check to see if the current subarray from start to end is valid
            if (currentSum <= k && (end == start || isDivisible(h[end-1], h[end]))) {
                maxLength = max(maxLength, end - start + 1);
            }
        }
        
        return maxLength;
    }
    
private:
    bool isDivisible(int x, int y) {
        return x % y == 0;
    }
};


#endif