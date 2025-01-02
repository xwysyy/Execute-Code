#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // Count odd numbers at even and odd indices
        int oddAtEven = 0, oddAtOdd = 0;
        
        for(int i = 0; i < n; i++) {
            if(a[i] % 2 == 1) {  // if number is odd
                if(i % 2 == 0)    // if index is even
                    oddAtEven++;
                else              // if index is odd
                    oddAtOdd++;
            }
        }
        
        // If we can make all numbers even or all numbers odd
        if(oddAtEven == 0 && oddAtOdd == 0) return "YES";  // all even already
        if(oddAtEven == (n+1)/2 && oddAtOdd == n/2) return "YES";  // can make all odd
        
        return "NO";
    }
};


#endif