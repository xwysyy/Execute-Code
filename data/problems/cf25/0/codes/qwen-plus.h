#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n) {   
        if (n == 1) return "YES"; // Special case for single vertex
        
        for (int k = 2; k * k <= n; ++k) {
            int sum = 1;
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