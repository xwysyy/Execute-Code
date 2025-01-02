#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, vector<int> &a) {
        // Count frequency of numbers that could be part of a permutation
        vector<int> freq(n + 1, 0);
        int valid_nums = 0;
        long long cost = 0;
        
        // Count valid numbers (1 to n) and mark numbers to remove
        for (int x : a) {
            if (x <= n) {
                freq[x]++;
                if (freq[x] == 1) valid_nums++;
            }
        }
        
        // Remove extra occurrences of numbers and numbers > n
        for (int x : a) {
            if (x > n || freq[x] > 1) {
                cost += c;
                if (x <= n) freq[x]--;
            }
        }
        
        // Find smallest possible target length for permutation
        int target_len = 1;
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 1) target_len = i;
        }
        
        // Add missing numbers to complete the permutation
        for (int i = 1; i <= target_len; i++) {
            if (freq[i] == 0) {
                cost += d;
            }
        }
        
        return cost;
    }
};


#endif