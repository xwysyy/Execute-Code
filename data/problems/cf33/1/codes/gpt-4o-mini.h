#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, int &x, vector<int> &a) {
        // Sort the array to facilitate optimal removal and flipping
        sort(a.begin(), a.end());
        
        // Alice removes up to k smallest elements
        for (int i = 0; i < k && !a.empty(); ++i) {
            a.pop_back(); // remove the smallest elements
        }
        
        // Now we need to consider Bob's actions on the remaining elements
        // Sort the remaining elements to facilitate flipping the largest ones
        sort(a.begin(), a.end(), greater<int>());
        
        // Bob will flip up to x largest remaining elements
        for (int i = 0; i < x && i < a.size(); ++i) {
            a[i] = -a[i]; // flip the sign of these elements
        }
        
        // Calculate the final sum of the array
        int final_sum = 0;
        for (int num : a) {
            final_sum += num; // accumulate the modified array
        }
        
        return final_sum; // return the final sum result
    }
};


#endif