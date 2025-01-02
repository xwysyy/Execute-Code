#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // To minimize the disturbance, we need to arrange the array such that
        // consecutive elements are as different as possible.
        // One way to achieve this is to sort the array and then arrange it in a way
        // that no two consecutive elements are the same.
        // However, since we can swap any two symmetric positions, we can rearrange
        // the array in any order we want.
        // Therefore, the minimal disturbance is the number of pairs of consecutive
        // elements that are the same after rearranging the array to minimize such pairs.
        // The minimal disturbance is the maximum frequency of any element minus one,
        // but not less than zero.

        // Count the frequency of each element
        unordered_map<int, int> freq;
        for (int num : a) {
            freq[num]++;
        }

        // Find the maximum frequency
        int max_freq = 0;
        for (auto &pair : freq) {
            if (pair.second > max_freq) {
                max_freq = pair.second;
            }
        }

        // The minimal disturbance is max_freq - 1, but not less than zero
        return max(0, max_freq - 1);
    }
};


#endif