#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {   
        int r = 0, c = 0;
        while (true) {
            if (r == 1 && c == n - 1) return "YES";
            if (c < 0 || c >= n || r < 0 || r >= 2) return "NO";
            
            // Move down or up
            if (r == 0 && s1[c] == '<') c--;
            else if (r == 0 && s1[c] == '>') c++;
            else if (r == 1 && s2[c] == '<') c--;
            else if (r == 1 && s2[c] == '>') c++;
            
            // Move along the arrow
            if (r == 0 && s1[c] == '<') c--;
            else if (r == 0 && s1[c] == '>') c++;
            else if (r == 1 && s2[c] == '<') c--;
            else if (r == 1 && s2[c] == '>') c++;
            
            // Check if we are out of bounds
            if (c < 0 || c >= n) return "NO";
            
            // Move to the next row
            r = 1 - r;
        }
        return "NO";
    }
};

#endif