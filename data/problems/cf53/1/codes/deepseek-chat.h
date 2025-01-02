#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        std::unordered_map<int, int> freq;
        for (int num : a) {
            freq[num]++;
        }
        int maxFreq = 0;
        for (auto &pair : freq) {
            if (pair.second > maxFreq) {
                maxFreq = pair.second;
            }
        }
        // The minimal disturbance is max(0, maxFreq - (n - maxFreq + 1))
        // But more precisely, it's max(0, maxFreq - (n + 1) / 2)
        int minimalDisturbance = std::max(0, maxFreq - (n + 1) / 2);
        return minimalDisturbance;
    }
};


#endif