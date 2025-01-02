#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        if (n % 2 == 1) {
            for (int i = 0; i < n; ++i) {
                if (s[i] == 'E' && s[(i + 1) % n] == 'E' && s[(i + 2) % n] == 'E') {
                    return "YES";
                }
            }
            
            bool all_n = true;
            for(char c : s) {
                if(c == 'E') {
                    all_n = false;
                    break;
                }
            }
            if(all_n) return "YES";
            
            return "NO";
        } else {
            int e_count = 0;
            for (char c : s) {
                if (c == 'E') {
                    e_count++;
                }
            }
            if (e_count == n) return "YES";
            return "YES";
        }
    }
};


#endif