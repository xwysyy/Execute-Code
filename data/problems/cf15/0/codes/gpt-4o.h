#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int &n, vector<int> &a) {
        vector<int> result(n);
        unordered_map<int, int> frequency;
        int current_max = 0;
        
        for (int i = 0; i < n; ++i) {
            int num = a[i];
            frequency[num]++;
            
            // Update the current maximum element seen so far
            current_max = num;
            
            // The cost is the frequency of the maximum element till now
            result[i] = frequency[current_max];
        }
        
        return result;
    }
};


#endif