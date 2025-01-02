#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        // Calculate the initial number of inversions
        long long initial_inversions = 0;
        int count_ones = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                count_ones++;
            } else {
                initial_inversions += count_ones;
            }
        }
        
        // Calculate the maximum possible inversions after flipping each element
        long long max_inversions = initial_inversions;
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) {
                // If we flip 1 to 0, we lose the inversions caused by this 1
                // and gain the inversions caused by the 0s after it
                long long new_inversions = initial_inversions - (i - count_ones + 1) + (n - i - 1 - (count_ones - 1));
                max_inversions = max(max_inversions, new_inversions);
            } else {
                // If we flip 0 to 1, we gain the inversions caused by this 1
                // and lose the inversions caused by the 1s before it
                long long new_inversions = initial_inversions + (count_ones) - (n - i - 1 - count_ones);
                max_inversions = max(max_inversions, new_inversions);
            }
        }
        
        return max_inversions;
    }
};


#endif