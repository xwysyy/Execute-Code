#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        vector<int> odd, even;
        
        // Separate even and odd numbers
        for(int num : a) {
            if(num % 2 == 0) {
                even.push_back(num);
            } else {
                odd.push_back(num);
            }
        }
        
        // Sort the even and odd arrays
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        
        // Merge them back into a sorted array
        int evenIndex = 0, oddIndex = 0;
        vector<int> sorted(n);
        
        for(int i = 0; i < n; i++) {
            if(a[i] % 2 == 0) {
                sorted[i] = even[evenIndex++];
            } else {
                sorted[i] = odd[oddIndex++];
            }
        }
        
        // Check if the merged array is sorted
        for(int i = 1; i < n; i++) {
            if(sorted[i] < sorted[i - 1]) {
                return "NO";
            }
        }
        
        return "YES";
    }
};


#endif