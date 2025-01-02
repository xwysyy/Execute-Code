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
            // We need last i bits to be 0
            string curr = s;
            long long ops = 0;
            bool possible = true;
            
            // Start from the end and try to move 1s to the left
            for(int j = n-1; j >= n-i; j--) {
                if(curr[j] == '1') {
                    // Try to swap this 1 with 0s to the left
                    int pos = j;
                    while(pos > 0 && curr[pos] == '1') {
                        swap(curr[pos], curr[pos-1]);
                        ops++;
                        pos--;
                    }
                    // If we couldn't move the 1 out of the last i positions
                    if(pos <= 0 && curr[n-1-(n-1-j)] == '1') {
                        possible = false;
                        break;
                    }
                }
            }
            
            result[i-1] = possible ? ops : -1;
        }
        
        return result;
    }
};


#endif