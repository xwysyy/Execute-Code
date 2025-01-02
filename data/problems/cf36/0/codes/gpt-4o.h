#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> freq;
        int max_freq = 0;
        
        for (int i = 0; i < n; ++i) {
            int difference = a[i] - i;
            freq[difference]++;
            max_freq = max(max_freq, freq[difference]);
        }
        
        return max_freq;
    }
};


#endif