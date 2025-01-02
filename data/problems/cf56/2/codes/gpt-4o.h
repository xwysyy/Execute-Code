#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m, int &k, std::string &s) {
        int timar_count = 0;
        int i = 0;

        while (i < n) {
            // Find the start of a segment of '0's
            if (s[i] == '0') {
                int start = i;
                
                // Count the length of the segment of '0's
                while (i < n && s[i] == '0') {
                    i++;
                }
                
                int length_of_zeros = i - start;
                
                // If the length of this segment is at least m,
                // we need to consider Timar operations
                if (length_of_zeros >= m) {
                    // Calculate the minimum Timar operations needed
                    timar_count += (length_of_zeros + k - 1) / k;
                }
            } else {
                i++;
            }
        }
        
        return timar_count;
    }
};


#endif