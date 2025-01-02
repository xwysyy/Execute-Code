#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {
        if (n == 1) {
            return "NO";
        }
        
        // Iterate through possible values of k
        for (int k = 2; k < n; ++k) {
            long long current_sum = 1;
            long long term = 1;
            
            // Build the geometric series: 1 + k + k^2 + ... until we reach or exceed n
            while (current_sum < n) {
                term *= k;
                current_sum += term;
                
                if (current_sum == n) {
                    return "YES";
                }
                
                if (term > n) {
                    // As `term` grows exponentially, this helps prevent unnecessary calculations
                    break;
                }
            }
            
            if (term > n) {
                break;
            }
        }
        
        return "NO";
    }
};


#endif