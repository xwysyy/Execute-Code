#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        vector<int> odd, even;
        
        // Separate odd and even numbers in the respective vectors
        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                even.push_back(a[i]);
            } else {
                odd.push_back(a[i]);
            }
        }
        
        // Sort both arrays independently
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        
        int oddIndex = 0, evenIndex = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                // Should match the next even number
                if (a[i] != even[evenIndex++]) {
                    return "NO";
                }
            } else {
                // Should match the next odd number
                if (a[i] != odd[oddIndex++]) {
                    return "NO";
                }
            }
        }
        
        return "YES";
    }
};


#endif