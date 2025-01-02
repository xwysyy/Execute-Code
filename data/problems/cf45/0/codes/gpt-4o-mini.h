#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {
        // Count the number of flowers for each unique petal count
        unordered_map<int, long long> flower_count;
        
        for (int petals : a) {
            flower_count[petals]++;
        }
        
        long long max_petals = 0;
        
        // We need to iterate over unique petal counts in sorted order
        vector<int> unique_petals;
        for (const auto& entry : flower_count) {
            unique_petals.push_back(entry.first);
        }
        sort(unique_petals.begin(), unique_petals.end());
        
        // Loop through each unique petal count and try to create bouquets
        for (size_t i = 0; i < unique_petals.size(); ++i) {
            int p = unique_petals[i]; // current petal count
            
            long long count_p = flower_count[p]; // number of flowers with p petals
            long long total_cost = count_p * p; // total cost for p petal flowers
            
            long long total_petals = count_p * p; // initial petals
            
            // Check if we can afford all p petal flowers
            if (total_cost <= m) {
                // If we can afford all p petal flowers, see if we can add p + 1 petal flowers
                if (i + 1 < unique_petals.size() && unique_petals[i + 1] == p + 1) {
                    int next_p = unique_petals[i + 1];
                    long long count_next = flower_count[next_p];
                    long long additional_cost = count_next * next_p; // cost for p + 1 petal flowers
                    
                    // Check if we can afford all p + 1 flowers
                    if (total_cost + additional_cost <= m) {
                        // We can take all of these as well
                        total_petals += count_next * next_p;
                    } else {
                        // Calculate how many we can take of p + 1
                        long long affordable_next_count = (m - total_cost) / next_p;
                        total_petals += affordable_next_count * next_p;
                    }
                }
            } else {
                // If we cannot afford all p petal flowers, calculate how many we can take
                long long affordable_count = m / p;
                total_petals += affordable_count * p;
            }
            
            // Update the maximum petals found so far
            max_petals = max(max_petals, total_petals);
        }
        
        return max_petals;
    }
};


#endif