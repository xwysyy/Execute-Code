#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        if (n == 0) return "NO";
        
        // If all are 'E', then all elements must be the same
        bool allEqual = true;
        for (char c : s) {
            if (c != 'E') {
                allEqual = false;
                break;
            }
        }
        if (allEqual) return "YES";
        
        // Otherwise, we need to check if the constraints can be satisfied
        // We can model this as a bipartition problem
        // Assign 0 or 1 to each element, where 0 and 1 represent different values
        vector<int> color(n, -1);
        color[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            int next = (i + 1) % n;
            if (s[i] == 'E') {
                if (color[next] == -1) {
                    color[next] = color[i];
                } else if (color[next] != color[i]) {
                    return "NO";
                }
            } else if (s[i] == 'N') {
                if (color[next] == -1) {
                    color[next] = 1 - color[i];
                } else if (color[next] == color[i]) {
                    return "NO";
                }
            }
        }
        
        // Check the last and first element
        if (s[n-1] == 'E' && color[0] != color[n-1]) {
            return "NO";
        } else if (s[n-1] == 'N' && color[0] == color[n-1]) {
            return "NO";
        }
        
        return "YES";
    }
};


#endif