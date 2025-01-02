#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // Count initial parities at odd and even indices
        int oddAtOdd = 0, oddAtEven = 0;
        int evenAtOdd = 0, evenAtEven = 0;
        
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) { // even index
                if(a[i] % 2 == 0) evenAtEven++;
                else oddAtEven++;
            } else { // odd index
                if(a[i] % 2 == 0) evenAtOdd++;
                else oddAtOdd++;
            }
        }
        
        // Check if we can make all numbers even
        bool canMakeAllEven = (oddAtEven == 0 && oddAtOdd == 0) || // already all even
                             (oddAtEven > 0 && evenAtOdd == 0) ||   // can make even indices even and odd indices odd
                             (oddAtOdd > 0 && evenAtEven == 0);     // can make odd indices even and even indices odd
        
        // Check if we can make all numbers odd
        bool canMakeAllOdd = (evenAtEven == 0 && evenAtOdd == 0) || // already all odd
                            (evenAtEven > 0 && oddAtOdd == 0) ||     // can make even indices odd and odd indices even
                            (evenAtOdd > 0 && oddAtEven == 0);       // can make odd indices odd and even indices even
        
        return (canMakeAllEven || canMakeAllOdd) ? "YES" : "NO";
    }
};


#endif