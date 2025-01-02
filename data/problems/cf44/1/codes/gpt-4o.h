#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &l, int &r, vector<int> &a) { 
        int roundsWon = 0;
        int start = 0;
        long long currentSum = 0;
        
        for (int end = 0; end < n; ++end) {
            currentSum += a[end];
            
            while (start <= end && currentSum > r) {
                currentSum -= a[start];
                start++;
            }
            
            if (currentSum >= l && currentSum <= r) {
                roundsWon++;
                // Start new round, remove cards from the current
                currentSum -= a[start];
                start++;
            }
        }
        
        return roundsWon;
    }
};


#endif