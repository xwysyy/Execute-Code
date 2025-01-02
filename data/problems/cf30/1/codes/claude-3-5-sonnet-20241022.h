#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> result(n);
        
        // For each power of 2 (1 to n)
        for (int i = 1; i <= n; i++) {
            // We need last i bits to be 0
            int requiredZeros = i;
            long long swaps = 0;
            bool possible = true;
            string temp = s;
            
            // Start from the end and count required swaps
            for (int j = n - 1; j >= n - i; j--) {
                if (temp[j] == '1') {
                    // Try to find nearest 0 to swap with
                    int k = j;
                    while (k >= 0 && temp[k] == '1') k--;
                    
                    if (k < 0 || k < n - i) {
                        // Can't find a 0 to swap with
                        possible = false;
                        break;
                    }
                    
                    // Perform swaps by moving 0 to position j
                    while (k < j) {
                        swap(temp[k], temp[k + 1]);
                        swaps++;
                        k++;
                    }
                }
            }
            
            result[i - 1] = possible ? swaps : -1;
        }
        
        return result;
    }
};


#endif