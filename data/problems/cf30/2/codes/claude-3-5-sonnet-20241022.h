#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> result(n);
        
        // For each power of 2 (1 to n)
        for(int i = 1; i <= n; i++) {
            // Count how many 1s we need to move out of last i positions
            int ones = 0;
            for(int j = n-i; j < n; j++) {
                if(s[j] == '1') ones++;
            }
            
            // If there are no ones in last i positions, answer is 0
            if(ones == 0) {
                result[i-1] = 0;
                continue;
            }
            
            // Count available positions to move 1s
            int available = 0;
            for(int j = 0; j < n-i; j++) {
                if(s[j] == '0') available++;
            }
            
            // If we don't have enough positions to move all 1s
            if(available < ones) {
                result[i-1] = -1;
                continue;
            }
            
            // Calculate minimum swaps needed
            long long swaps = 0;
            string temp = s;
            for(int j = n-1; j >= n-i; j--) {
                if(temp[j] == '1') {
                    // Find rightmost 0 before position n-i
                    int pos = j-1;
                    while(pos >= 0 && temp[pos] == '1') pos--;
                    
                    // Swap 1 with 0s until we reach pos
                    for(int k = j; k > pos; k--) {
                        swap(temp[k], temp[k-1]);
                        swaps++;
                    }
                }
            }
            result[i-1] = swaps;
        }
        
        return result;
    }
};


#endif