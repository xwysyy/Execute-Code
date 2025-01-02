#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        // If all pairs are equal, then all elements must be the same
        if (s == string(n, 'E')) {
            return "YES";
        }
        // If all pairs are not equal, then it's impossible for n >= 3
        if (s == string(n, 'N')) {
            if (n == 2) {
                return "YES";
            } else {
                return "NO";
            }
        }
        // Check for consistency in the sequence
        // We can try to assign values to the array based on the sequence
        // Let's try to assign 0 and 1 to the elements
        vector<int> a(n);
        a[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] == 'E') {
                a[i] = a[i - 1];
            } else {
                a[i] = 1 - a[i - 1];
            }
        }
        // Now check the last pair
        if (s[n - 1] == 'E' && a[n - 1] != a[0]) {
            return "NO";
        }
        if (s[n - 1] == 'N' && a[n - 1] == a[0]) {
            return "NO";
        }
        return "YES";
    }
};


#endif