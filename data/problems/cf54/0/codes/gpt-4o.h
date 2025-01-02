#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        std::unordered_map<int, int> prefix_index_map;
        int prefix_sum = 0;
        int count = 0;
        int last_end = -1;
        
        for (int i = 0; i < n; ++i) {
            prefix_sum += a[i];
            
            if (prefix_sum == 0 && i > last_end) {
                count++;
                last_end = i;
            }
            
            if (prefix_index_map.find(prefix_sum) != prefix_index_map.end() && prefix_index_map[prefix_sum] >= last_end) {
                count++;
                last_end = i;
            }
            
            prefix_index_map[prefix_sum] = i;
        }
        
        return count;
    }
};


#endif