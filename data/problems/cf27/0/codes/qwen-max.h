#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string solve(int &n, vector<int> &a) {
        vector<int> odd, even;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                even.push_back(a[i]);
            } else {
                odd.push_back(a[i]);
            }
        }
        
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        
        int o = 0, e = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                if (a[i] != even[e]) {
                    return "NO";
                }
                e++;
            } else {
                if (a[i] != odd[o]) {
                    return "NO";
                }
                o++;
            }
        }
        return "YES";
    }
};

#endif