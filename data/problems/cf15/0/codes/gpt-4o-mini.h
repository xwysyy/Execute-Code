#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) { 
        vector<int> cost(n); // This will hold the costs for each prefix
        vector<int> count(n + 1, 0); // Count occurrences of each number in range 1 to n
        
        for (int k = 0; k < n; k++) {
            int value = a[k];
            count[value]++;
            // The maximum score can be obtained by counting all occurrences of the highest value seen so far
            int maxScoreCount = count[value];
            // Since `value` is the maximum so far and appears `maxScoreCount` times, the cost is simply that count
            cost[k] = maxScoreCount;
        }
        
        return cost;
    }
};


#endif