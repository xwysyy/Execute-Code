#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        std::unordered_map<int, int> frequency;
        int max_freq = 0;
        
        // Calculate the frequency of each interest topic
        for (int i = 0; i < n; ++i) {
            frequency[a[i]]++;
            max_freq = std::max(max_freq, frequency[a[i]]);
        }
        
        // Total elements minus max frequency gives the minimal disturbance
        return n - max_freq;
    }
};


#endif