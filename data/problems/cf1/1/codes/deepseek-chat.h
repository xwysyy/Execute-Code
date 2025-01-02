#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        std::unordered_map<int, int> freq;
        for (int coin : a) {
            freq[coin]++;
        }
        int max_freq = 0;
        for (const auto &pair : freq) {
            if (pair.second > max_freq) {
                max_freq = pair.second;
            }
        }
        return max_freq;
    }
};


#endif