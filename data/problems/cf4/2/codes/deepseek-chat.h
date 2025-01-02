#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s) {
        // If all pairs are equal, then all elements must be the same
        if (s.find('N') == string::npos) {
            return "YES";
        }
        // If all pairs are not equal, then we need to ensure that no two adjacent elements are the same
        if (s.find('E') == string::npos) {
            // For a circle, if n is odd, it's impossible to have all adjacent pairs different
            if (n % 2 == 1) {
                return "NO";
            } else {
                return "YES";
            }
        }
        // Otherwise, we need to check if the pattern is consistent
        // We can try to assign values to the array and see if it's possible
        // Since the array is circular, we need to ensure that the first and last elements also satisfy the condition
        // We can try to assign 0 and 1 alternately and see if it works
        vector<int> a(n);
        a[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i-1] == 'E') {
                a[i] = a[i-1];
            } else {
                a[i] = 1 - a[i-1];
            }
        }
        // Now check the last pair
        if (s[n-1] == 'E' && a[n-1] != a[0]) {
            return "NO";
        }
        if (s[n-1] == 'N' && a[n-1] == a[0]) {
            return "NO";
        }
        return "YES";
    }
};


#endif