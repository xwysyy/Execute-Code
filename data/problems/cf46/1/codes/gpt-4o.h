#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::string &s1, std::string &s2) {
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            // Check if we can block this cell to separate into 3 regions
            if (s1[i] == '.' && s2[i] == '.') {
                bool canSeparate = false;
                
                // Block s1[i] or s2[i] and check connectivity changes
                if (i > 0 && i < n-1) {
                    // Separate above and below if they are connected before blocking
                    bool beforeConnected = (s1[i-1] == '.' || s2[i-1] == '.') && (s1[i+1] == '.' || s2[i+1] == '.');
                    if (beforeConnected) {
                        bool afterSeparated1 = (s1[i-1] == 'x' && s2[i-1] == 'x' && s1[i+1] == 'x') || 
                                               (s1[i-1] == 'x' && s2[i+1] == 'x' && s2[i-1] == 'x');
                        bool afterSeparated2 = (s2[i-1] == 'x' && s1[i+1] == 'x' && s2[i+1] == 'x') || 
                                               (s2[i-1] == 'x' && s1[i-1] == 'x' && s1[i+1] == 'x');
                        if (afterSeparated1 || afterSeparated2) {
                            canSeparate = true;
                        }
                    }
                }
                
                if (i > 0 && s1[i-1] == 'x' && s2[i-1] == '.' && s2[i] == '.' && s1[i+1] == '.') {
                    canSeparate = true;
                }
                
                if (i > 0 && s2[i-1] == 'x' && s1[i-1] == '.' && s1[i] == '.' && s2[i+1] == '.') {
                    canSeparate = true;
                }
                
                if (canSeparate) {
                    count++;
                }
            }
        }
        
        return count;
    }
};


#endif