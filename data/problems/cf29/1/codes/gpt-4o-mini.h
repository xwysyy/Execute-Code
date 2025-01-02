#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {
        int maxLength = 0;
        int currentSum = 0;
        
        for (int l = 0; l < n; l++) {
            currentSum = 0; // Reset current sum for new starting index
            int r = l; // Start r from l
            
            while (r < n) {
                // Check divisibility condition
                if (r > l && h[r - 1] % h[r] != 0) {
                    break; // If condition fails, break
                }
                
                currentSum += a[r]; // Add fruits in the current window
                
                // If the sum exceeds k, move l to the right
                if (currentSum > k) {
                    break; // No point in extending r further
                }
                
                // Valid window [l...r] found, update maximum length
                maxLength = max(maxLength, r - l + 1);
                
                r++; // Move end pointer to the right
            }
        }
        
        return maxLength;
    }
};


#endif