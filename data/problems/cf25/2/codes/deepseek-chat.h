#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {
        if (n == 1) return "YES"; // The initial vertex is always valid
        
        // We need to find if n can be expressed as 1 + k + k^2 + ... + k^m where m >= 1 and k > 1
        // This is equivalent to n = (k^(m+1) - 1) / (k - 1)
        // We can iterate over possible k and m values to check if n can be expressed in this form
        
        // Iterate over possible k values (from 2 to sqrt(n))
        for (int k = 2; k * k <= n; ++k) {
            int sum = 1 + k; // Start with 1 (initial vertex) + k (first layer)
            int current = k * k; // Next layer
            while (sum + current <= n) {
                sum += current;
                if (sum == n) return "YES";
                current *= k;
            }
        }
        
        // Also, check for the case where k is large and m is 1
        // n = 1 + k
        if (n - 1 > 1 && (n - 1) * (n - 1) > n) {
            if (1 + (n - 1) == n) return "YES";
        }
        
        return "NO";
    }
};


#endif