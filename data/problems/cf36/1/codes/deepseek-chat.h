#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        // Sort the array a
        std::sort(a.begin(), a.end());
        
        // Create a permutation p that is [1, 2, ..., n]
        std::vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = i + 1;
        }
        
        // Sort the permutation p in descending order
        std::sort(p.rbegin(), p.rend());
        
        // Add the permutation p to the array a
        for (int i = 0; i < n; ++i) {
            a[i] += p[i];
        }
        
        // Count the frequency of each element in the modified array a
        std::unordered_map<int, int> freq;
        for (int num : a) {
            freq[num]++;
        }
        
        // Find the maximum frequency
        int max_freq = 0;
        for (auto& pair : freq) {
            if (pair.second > max_freq) {
                max_freq = pair.second;
            }
        }
        
        return max_freq;
    }
};


#endif