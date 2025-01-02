#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        vector<int> evens, odds;

        // Separate the numbers into two lists: evens and odds
        for (int num : a) {
            if (num % 2 == 0) {
                evens.push_back(num);
            } else {
                odds.push_back(num);
            }
        }

        // Sort the original array
        vector<int> sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end());

        // Check if the even elements can be sorted separately
        if (!is_sorted(evens.begin(), evens.end()) && !is_sorted(evens.begin(), sorted_a.begin() + evens.size())) {
            return "NO";
        }

        // Check if the odd elements can be sorted separately
        if (!is_sorted(odds.begin(), odds.end()) && !is_sorted(odds.begin(), sorted_a.begin() + odds.size())) {
            return "NO";
        }

        return "YES";
    }
};


#endif