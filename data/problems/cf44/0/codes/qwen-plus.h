#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, vector<int> &a) { 
        int maxRounds = 0;
        int currentSum = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            currentSum += a[end];

            // If the current sum exceeds 'r', adjust the start index to try and get the sum within range
            while (currentSum > r && start <= end) {
                currentSum -= a[start];
                start++;
            }

            // Check if the current window is a valid round
            if (currentSum >= l && currentSum <= r) {
                maxRounds++;
                currentSum = 0;
                start = end + 1;
            }
        }

        return maxRounds;
    }
};


#endif