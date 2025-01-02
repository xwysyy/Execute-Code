#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {   
        int n = a.size();
        vector<int> max_one_a(n, -1), min_zero_a(n, n);
        vector<int> max_one_b(n, -1), min_zero_b(n, n);
        
        // For string a
        int last_one = -1, first_zero = n;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1') {
                last_one = i;
            } else {
                first_zero = min(first_zero, i);
            }
            max_one_a[i] = last_one;
            min_zero_a[i] = first_zero;
        }
        
        // For string b
        last_one = -1, first_zero = n;
        for (int i = 0; i < n; ++i) {
            if (b[i] == '1') {
                last_one = i;
            } else {
                first_zero = min(first_zero, i);
            }
            max_one_b[i] = last_one;
            min_zero_b[i] = first_zero;
        }
        
        // Check if we can make the strings equal
        for (int i = 0; i < n; ++i) {
            if ((max_one_a[i] >= i || min_zero_a[i] <= i) != (max_one_b[i] >= i || min_zero_b[i] <= i)) {
                return "NO";
            }
        }
        return "YES";
    }
};


#endif