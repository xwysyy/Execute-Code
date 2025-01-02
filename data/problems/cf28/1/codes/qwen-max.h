#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        int n = a.length();
        int i = 0, j = n - 1;
        
        // Move i to the first differing character from the left
        while (i < n && a[i] == b[i]) {
            i++;
        }
        
        // Move j to the first differing character from the right
        while (j >= 0 && a[j] == b[j]) {
            j--;
        }
        
        // If all characters are the same, return "YES"
        if (i >= j) {
            return "YES";
        }
        
        // Check if we can make the substrings equal by transforming
        for (int k = i; k <= j; ++k) {
            if (a[k] != a[i] && a[k] != a[j]) {
                return "NO";
            }
            if (b[k] != b[i] && b[k] != b[j]) {
                return "NO";
            }
        }
        
        // Check if the end characters of the differing segment are the same
        if (a[i] == b[j] && a[j] == b[i]) {
            return "YES";
        }
        
        return "NO";
    }
};

#endif