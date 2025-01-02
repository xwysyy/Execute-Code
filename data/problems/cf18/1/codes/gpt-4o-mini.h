#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &c, int &d, std::vector<int> &a) {
        std::unordered_set<int> unique_values(a.begin(), a.end());
        int count_unique = unique_values.size(); // Count of unique integers
        
        // Calculate the number of duplicates
        int num_duplicates = n - count_unique; 
        
        // Determine the minimum required size for a valid permutation
        // This can be done by taking the maximum of the present distinct numbers or 
        // the number of required integers (1 to count_unique + num_duplicates)
        long long current_cost = 0;
        
        // If we keep the unique values but remove duplicates
        current_cost += num_duplicates * c; // Cost to remove duplicates
        
        // If we need to add integers to have a complete permutation
        long long total_needed = count_unique; // this is the existing unique numbers
        long long needed_to_add = std::max(0LL, total_needed - count_unique);
        
        // If we want a permutation of size = count_unique + needed_to_add
        long long add_cost = needed_to_add * d; 

        // Total cost if we keep current distinct numbers (remove duplicates and add)
        current_cost += add_cost;
        
        // Also consider deleting the entire array and starting fresh
        long long clear_cost = c * n + d; // Clear cost and adding at least one
        
        // Return the minimal cost
        return std::min(current_cost, clear_cost);
    }
};


#endif