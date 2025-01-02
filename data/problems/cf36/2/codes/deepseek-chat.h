#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Sort the array to pair with the permutation
        sort(a.begin(), a.end());
        
        // Create a map to count the frequency of each adjusted value
        unordered_map<int, int> freq;
        int maxFreq = 0;
        
        // Pair each element with i+1 (permutation value) and count frequencies
        for (int i = 0; i < n; i++) {
            int adjustedValue = a[i] + (i + 1);
            freq[adjustedValue]++;
            if (freq[adjustedValue] > maxFreq) {
                maxFreq = freq[adjustedValue];
            }
        }
        
        return maxFreq;
    }
};


#endif