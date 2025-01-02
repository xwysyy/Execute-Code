#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        int n = a.size();
        int i = 0, j = n - 1;
        
        // Move i to the right until we find a difference
        while (i < n && a[i] == b[i]) {
            i++;
        }
        
        // Move j to the left until we find a difference
        while (j >= 0 && a[j] == b[j]) {
            j--;
        }
        
        // If all characters are the same, return "YES"
        if (i > j) {
            return "YES";
        }
        
        // Check if the remaining parts of both strings can be made equal
        char ch1 = a[i], ch2 = a[j];
        for (int k = i; k <= j; k++) {
            if (a[k] != ch1 && a[k] != ch2) {
                return "NO";
            }
            if (b[k] != ch1 && b[k] != ch2) {
                return "NO";
            }
        }
        
        return "YES";
    }
};

#endif