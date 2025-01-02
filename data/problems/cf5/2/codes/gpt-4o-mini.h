#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        if (n < 3) return -1; // If less than 3 elements, it's impossible to have a value appear three times.

        unordered_map<int, int> freq; // To store frequency of each number.
        
        for (int num : a) {
            freq[num]++;
        }
        
        int minValue = INT_MAX; // To track the minimum value that appears at least three times.
        bool found = false; // Flag to check if we found any value appearing three times.
        
        for (const auto &entry : freq) {
            if (entry.second >= 3) { // Check if the frequency is at least 3.
                found = true;
                if (entry.first < minValue) { // Update minValue if current number is less.
                    minValue = entry.first;
                }
            }
        }
        
        return found ? minValue : -1; // Return the minimum value or -1 if no such value exists.
    }
};


#endif