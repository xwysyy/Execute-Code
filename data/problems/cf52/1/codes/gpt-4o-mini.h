#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<vector<int>> &a) {
        long long operations = 0; // this will count the total number of operations
        
        // Iterate through the entire matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] < 0) { // found a lake
                    operations += -a[i][j]; // we need this many operations to make it zero or positive
                    
                    // After counting the operations, we set the lake value to zero
                    a[i][j] = 0;
                }
            }
        }
        
        return operations; // return the total number of magic operations needed
    }
};


#endif