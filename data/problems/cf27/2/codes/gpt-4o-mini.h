#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, vector<int> &a) {
        vector<int> odd, even;
        
        // Split the numbers into odds and evens
        for (int num : a) {
            if (num % 2 == 0) {
                even.push_back(num);
            } else {
                odd.push_back(num);
            }
        }
        
        // Sort the odd and even numbers separately
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        
        // Reconstruct the array by placing sorted odds and evens back
        vector<int> sorted_a;
        int odd_index = 0, even_index = 0;
        
        for (int num : a) {
            if (num % 2 == 0) {
                sorted_a.push_back(even[even_index++]);
            } else {
                sorted_a.push_back(odd[odd_index++]);
            }
        }
        
        // Compare sorted array with original sorted array
        vector<int> original_sorted_a = a;
        sort(original_sorted_a.begin(), original_sorted_a.end());
        
        if (sorted_a == original_sorted_a) {
            return "YES";
        } else {
            return "NO";
        }
    }
};


#endif