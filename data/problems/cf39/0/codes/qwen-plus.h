#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {   
        // Check if the robot can reach the cell (2, n)
        for (int i = 0; i < n; ++i) {
            // If the robot is in the first row
            if (i == 0 && s1[i] == '<') return "NO";
            if (i > 0 && s1[i] == '<' && s2[i-1] == '>') return "NO";
            
            // If the robot is in the second row
            if (i == n-1 && s2[i] == '>') return "NO";
            if (i < n-1 && s2[i] == '>' && s1[i+1] == '<') return "NO";
        }
        
        // Check if there's a way to switch rows without getting stuck
        for (int i = 0; i < n; ++i) {
            if (s1[i] == '<' && s2[i] == '>') return "YES";
            if (s1[i] == '>' && s2[i] == '<') return "YES";
        }
        
        // If none of the above conditions are met, check if direct path exists
        if (s1[n-1] == '>' || s2[n-1] == '<') return "YES";
        
        return "NO";
    }
};


#endif