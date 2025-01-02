#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::string solve(int &n, std::string &s) {
        // The number of separate groups of consecutive 'U's will determine Alice's fate
        int grundy = 0;
        std::vector<int> counts;
        int currentCount = 0;
        
        // Traverse the string to compute consecutive 'U'-blocks
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'U') {
                currentCount++;
            } else {
                if (currentCount > 0) {
                    counts.push_back(currentCount);
                }
                currentCount = 0;
            }
        }
        // Push the last block if it exists
        if (currentCount > 0) {
            counts.push_back(currentCount);
        }

        // Calculate the Grundy number for each block, which for a block of size k is simply k.
        for (int count : counts) {
            grundy ^= count;
        }
        
        // If the grundy number is non-zero, Alice, the first player, will win.
        if (grundy != 0) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif