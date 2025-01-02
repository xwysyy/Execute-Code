#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        int saved_magazines = 0;
        int carry = 0; // This indicates if we have a lid to cover current box from previous move

        for (int i = 0; i < n; ++i) {
            // If carry is 1, it means previous operation left a lid for this box
            if (carry == 1) {
                saved_magazines += a[i]; // Use it to cover this box
                carry = 0; // Lid is now used
            }
            if (s[i] == '1') {
                // This box is covered, add its magazines to saved count
                saved_magazines += a[i];
                // Potentially leave a carry for the next box
                carry = 1;
            }
        }
        return saved_magazines;
    }
};


#endif