#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        std::unordered_map<int, int> frequencyMap;
        int maxFrequency = 0;

        // Iterate over the array to compute a[i] - i
        // and build the frequency map
        for (int i = 0; i < n; ++i) {
            int key = a[i] - (i + 1); // Calculate key for the map
            frequencyMap[key]++;
            // Update the max frequency if necessary
            if (frequencyMap[key] > maxFrequency) {
                maxFrequency = frequencyMap[key];
            }
        }
        return maxFrequency; // Return the maximum frequency found
    }
};


#endif