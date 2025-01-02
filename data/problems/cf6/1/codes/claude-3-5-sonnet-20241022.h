#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // Count initial parities at odd and even indices
        int oddAtEven = 0, oddAtOdd = 0;
        
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {  // even index
                if(a[i] % 2 == 1) oddAtEven++;
            } else {          // odd index
                if(a[i] % 2 == 1) oddAtOdd++;
            }
        }
        
        // Count total numbers at odd and even positions
        int evenCount = (n + 1) / 2;  // ceiling of n/2
        int oddCount = n / 2;         // floor of n/2
        
        // Check if we can make all numbers even
        bool canMakeAllEven = (oddAtEven == 0 && oddAtOdd == 0) ||  // already all even
                             (oddAtEven == evenCount && oddAtOdd == oddCount);
        
        // Check if we can make all numbers odd
        bool canMakeAllOdd = (oddAtEven == evenCount && oddAtOdd == 0) ||
                            (oddAtEven == 0 && oddAtOdd == oddCount);
        
        return (canMakeAllEven || canMakeAllOdd) ? "YES" : "NO";
    }
};


#endif