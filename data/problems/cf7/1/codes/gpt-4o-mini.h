#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        int saved = 0;
        
        // Process each box
        for (int i = 0; i < n; ++i) {
            // If this box has a lid, save the magazines in it
            if (s[i] == '1') {
                saved += a[i]; // Save magazines in box i
            }
            // If this box does not have a lid
            else {
                // Check if we can move a lid from the previous box
                if (i > 0 && s[i - 1] == '1') {
                    saved += a[i]; // Save magazines in box i using lid from box i-1
                    // We will assume the lid is now 'used' and switch s[i-1] to '0'
                    s[i - 1] = '0'; // Move lid from box i-1 to box i
                }
            }
        }
        
        return saved;
    }
};


#endif