#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) {   
        vector<int> result(n);
        
        int currentCount = 0;
        int currentNumber = -1;
        
        for (int i = 0; i < n; ++i) {
            if (a[i] == currentNumber) {
                currentCount++;
            } else {
                currentNumber = a[i];
                currentCount = 1;
            }
            
            // For each position i, the cost is the currentCount of the currentNumber
            result[i] = currentCount;
        }
        
        return result;
    }
};


#endif