#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        bool possible = true;
        bool odd_parity = (a[0] % 2 != 0);
        for (int i = 0; i < n; i += 2) {
            if (a[i] % 2 != odd_parity) {
                possible = false;
                break;
            }
        }
        if (possible) {
            return "YES";
        }
        possible = true;
        bool even_parity = (a[0] % 2 == 0);
        for (int i = 0; i < n; i += 2) {
            if (a[i] % 2 != even_parity) {
                possible = false;
                break;
            }
        }

        if (possible) {
            return "YES";
        }


        possible = true;
        odd_parity = (a[1] % 2 != 0);

        for (int i = 1; i < n; i += 2) {
            if (a[i] % 2 != odd_parity) {
                possible = false;
                break;
            }
        }
        if (possible) {
             return "YES";
        }

        possible = true;
        even_parity = (a[1] % 2 == 0);
        for (int i = 1; i < n; i += 2) {
            if (a[i] % 2 != even_parity) {
                possible = false;
                break;
            }
        }
        if (possible) {
            return "YES";
        }

        return "NO";
    }
};


#endif