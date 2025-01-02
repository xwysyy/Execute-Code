#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n < 3) return -1; // If there are less than 3 elements, no value can appear three times
        
        unordered_map<int, int> freqMap;
        for (int num : a) {
            freqMap[num]++;
            if (freqMap[num] >= 3) {
                return num; // Return the first value that appears at least three times
            }
        }
        
        return -1; // If no value appears at least three times
    }
};


#endif