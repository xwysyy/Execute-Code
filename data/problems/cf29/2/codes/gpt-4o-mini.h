#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<int> &a, vector<int> &h) {   
        int maxLength = 0;
        int currentFruits = 0;
        int left = 0;

        for (int right = 0; right < n; ++right) {
            currentFruits += a[right]; // Include the current fruit
            
            // Ensure divisibility condition and sum of fruits condition
            while (left < right && (currentFruits > k || (right > left && h[left] % h[left + 1] != 0))) {
                currentFruits -= a[left]; // Move left pointer and subtract fruits
                left++;
            }
            
            // If we have a valid segment, update the maxLength
            if (currentFruits <= k) {
                maxLength = max(maxLength, right - left + 1);
            }
        }
        
        return maxLength;
    }
};


#endif