#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(string &a, string &b) {
        int n = a.length();
        int i = 0, j = n - 1;
        
        // Move i to the right until a[i] and b[i] differ
        while (i < n && a[i] == b[i]) {
            i++;
        }
        
        // Move j to the left until a[j] and b[j] differ
        while (j >= 0 && a[j] == b[j]) {
            j--;
        }
        
        // If all characters are the same, return "YES"
        if (i > j) {
            return "YES";
        }
        
        // Check if the remaining parts of a and b can be made equal
        for (int k = i; k <= j; k++) {
            if (a[k] != a[i] || b[k] != b[j]) {
                return "NO";
            }
        }
        
        return "YES";
    }
};

#endif