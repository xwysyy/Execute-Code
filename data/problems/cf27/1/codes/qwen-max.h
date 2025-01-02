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
        
        vector<int> sortedArray;
        int oddIndex = 0, evenIndex = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                sortedArray.push_back(even[evenIndex++]);
            } else {
                sortedArray.push_back(odd[oddIndex++]);
            }
        }
        
        for (int i = 1; i < n; i++) {
            if (sortedArray[i] < sortedArray[i - 1]) {
                return "NO";
            }
        }
        
        return "YES";
    }
};

#endif