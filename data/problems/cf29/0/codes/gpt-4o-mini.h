#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {
        int left = 0, totalFruits = 0, maxLength = 0;

        for (int right = 0; right < n; right++) {
            // Add the current tree's fruits into the total
            totalFruits += a[right];

            // Check the divisibility condition and adjust left if necessary
            while (left < right && (h[right - 1] % h[right] != 0 || totalFruits > k)) {
                totalFruits -= a[left];
                left++;
            }
            
            // If the window is valid and within the fruit limit, calculate length
            if (totalFruits <= k) {
                maxLength = max(maxLength, right - left + 1);
            }
        }
        
        return maxLength;
    }
};


#endif