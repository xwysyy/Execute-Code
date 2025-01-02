#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        // Check parities for odd and even indexed elements
        bool parity_odd = true, parity_even = true;
        
        // Finding out the initial parity of the first odd and even positions
        int first_odd_parity = a[1] % 2;  // Assuming at least 2 elements exist as per constraints
        int first_even_parity = a[0] % 2;
        
        for (int i = 1; i < n; i += 2) {
            if (a[i] % 2 != first_odd_parity) {
                parity_odd = false;
                break;
            }
        }
        
        for (int i = 0; i < n; i += 2) {
            if (a[i] % 2 != first_even_parity) {
                parity_even = false;
                break;
            }
        }
        
        if (parity_odd && parity_even) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif