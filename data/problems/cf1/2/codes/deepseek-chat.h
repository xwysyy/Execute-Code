#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> frequency;
        for (int coin : a) {
            frequency[coin]++;
        }
        int maxFreq = 0;
        for (auto& pair : frequency) {
            if (pair.second > maxFreq) {
                maxFreq = pair.second;
            }
        }
        return maxFreq;
    }
};


#endif