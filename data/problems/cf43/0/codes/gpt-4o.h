#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) { 
        std::unordered_map<int, int> frequency;
        int max_frequency = 0;
        int max_value = a[0];

        // Count the frequency of each element
        for (int num : a) {
            frequency[num]++;
            if (frequency[num] > max_frequency) {
                max_frequency = frequency[num];
                max_value = num;
            } else if (frequency[num] == max_frequency) {
                max_value = std::max(max_value, num);
            }
        }

        return max_value;
    }
};


#endif