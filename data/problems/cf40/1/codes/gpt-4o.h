#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(string &s) {
        int n = s.size();
        
        // Function to check if s[l:r+1] can be made into tandem repeat of size len
        auto canFormTandem = [&](int len) -> bool {
            for (int start = 0; start <= n - len; start++) {
                int halfLen = len / 2;
                bool isTandem = true;

                for (int i = 0; i < halfLen; i++) {
                    char first = s[start + i];
                    char second = s[start + i + halfLen];

                    // Either they are equal or one of them is '?'
                    if (first != '?' && second != '?' && first != second) {
                        isTandem = false;
                        break;
                    }
                }
                
                if (isTandem) return true;
            }
            return false;
        };
        
        // Looking for the longest even length starting from the largest possible
        for (int len = (n / 2) * 2; len >= 2; len -= 2) {
            if (canFormTandem(len)) {
                return len;
            }
        }
        
        return 0; // No valid tandem repeat if length < 2
    }
};


#endif