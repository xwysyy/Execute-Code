#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        // Sort the array to align with the permutation
        std::sort(a.begin(), a.end());
        
        // Transform the array by adding the permutation
        std::vector<int> transformed(n);
        for (int i = 0; i < n; ++i) {
            transformed[i] = a[i] + (i + 1);
        }
        
        // Count the frequency of each transformed element
        std::unordered_map<int, int> freq;
        for (int num : transformed) {
            freq[num]++;
        }
        
        // Find the maximum frequency
        int max_freq = 0;
        for (const auto& pair : freq) {
            if (pair.second > max_freq) {
                max_freq = pair.second;
            }
        }
        
        return max_freq;
    }
};


#endif