#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        bool possible_even = true;
        bool possible_odd = true;

        // Check if making all elements even is possible
        for (int i = 0; i < n; i += 2) {
            if (a[i] % 2 != 0) {
                possible_even = false;
                break;
            }
        }
        for (int i = 1; i < n; i += 2) {
            if (a[i] % 2 != 0) {
                possible_even = false;
                break;
            }
        }


        // Check if making all elements odd is possible
        for (int i = 0; i < n; i += 2) {
            if (a[i] % 2 != 1) {
                possible_odd = false;
                break;
            }
        }
        for (int i = 1; i < n; i += 2) {
            if (a[i] % 2 != 1) {
                possible_odd = false;
                break;
            }
        }

        
        bool even_odd = true;
        for(int i = 0; i < n; ++i){
            if(i % 2 == 0){
                if(a[i] % 2 != a[0] % 2)
                    even_odd = false;
            } else {
                if(a[i] % 2 != a[1] % 2)
                    even_odd = false;
            }
        }

        if(even_odd || possible_even || possible_odd)
            return "YES";

        return "NO";
    }
};


#endif