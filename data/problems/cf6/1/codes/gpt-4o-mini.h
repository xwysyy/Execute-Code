#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {   
        int odd_count = 0, even_count = 0;
        
        // Count how many odd and even indexed elements are odd
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) { // even index (0-based)
                if (a[i] % 2 != 0) even_count++;
            } else { // odd index (0-based)
                if (a[i] % 2 != 0) odd_count++;
            }
        }
        
        // Check if we can make all elements even or all elements odd
        // We can make all even if even indexed elements are even or
        // if the odd indexed elements can also be made even.
        // We can make all odd if odd indexed elements are odd or
        // if the even indexed elements can also be made odd.
        
        if ((even_count == 0 || odd_count == 0) || 
            (even_count > 0 && odd_count > 0 && (even_count % 2) == (odd_count % 2))) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif