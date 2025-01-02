#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, int &m, int &k, string &s) {
        int count = 0;
        for (int i = 0; i <= n - m; ) {
            bool found = false;
            for (int j = i; j < i + m; ++j) {
                if (s[j] == '1') {
                    found = true;
                    break;
                }
            }
            if (!found) {
                count++;
                int pos = i + m -1;
                if(pos + k > n)
                  pos = n - k;
                
                for (int j = pos; j < pos + k; ++j) {
                    s[j] = '1';
                }
                i += m;
            } else {
                i++;
            }
        }
        return count;
    }
};


#endif