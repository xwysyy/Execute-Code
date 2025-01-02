#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, std::string &s) {
        int minTimar = 0;
        
        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                // Starting point of a weak spots interval
                int j = i;
                // Find end of the weak spot interval
                while (j < n && s[j] == '0') {
                    j++;
                }
                // Length of this weak spot interval
                int len = j - i;
                
                // If the interval is at least of length m, we need to strengthen it
                if (len >= m) {
                    // Calculate how many Timar actions are needed for this interval.
                    int neededActions = (len - (m - 1) + k - 1) / k; // equivalent to ceil((len - (m-1)) / k)
                    minTimar += neededActions;
                }
                
                // Move i to the next position (end of the current interval of '0's)
                i = j;
            } else {
                // Move to the next character if it's a '1'
                i++;
            }
        }
        
        return minTimar;
    }
};


#endif