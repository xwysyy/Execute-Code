#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {
        if (n == 1) return "YES"; // Base case: initial vertex
        
        // We need to find if n can be expressed as 1 + k + k^2 + ... + k^m, where k > 1 and m >= 1
        // This is equivalent to n = (k^(m+1) - 1) / (k - 1)
        
        // Iterate over possible k values
        for (int k = 2; k <= sqrt(n) + 1; ++k) {
            int sum = 1; // Start with the initial vertex
            int current = k;
            while (sum + current <= n) {
                sum += current;
                if (sum == n) return "YES";
                current *= k;
            }
        }
        
        return "NO";
    }
};


#endif