#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s1, string &s2) {
        int count = 0;

        for (int i = 0; i < n; ++i) {
            // We want to check each free cell (.)
            if (s1[i] == '.' || s2[i] == '.') {
                // First, we will simulate blocking the cell
                char original1 = s1[i];
                char original2 = s2[i];
                
                if (s1[i] == '.') s1[i] = 'x'; // Block cell in row 1
                if (s2[i] == '.') s2[i] = 'x'; // Block cell in row 2
                
                // Count the number of regions after blocking
                bool visited[2] = { false, false }; // For rows 1 and 2
                int regions = 0;

                // Check for regions in row 1
                for (int j = 0; j < n; ++j) {
                    if (s1[j] == '.' && !visited[0]) {
                        // Found a new region in row 1
                        regions++;
                        visited[0] = true; // Mark row 1 as visited
                        // Move forward until we hit a blocked cell
                        while (j < n && s1[j] == '.') j++;
                    } else if (s1[j] == 'x') {
                        visited[0] = false; // Reset for next region
                    }
                }

                visited[0] = false; // Reset for row 2
                // Check for regions in row 2
                for (int j = 0; j < n; ++j) {
                    if (s2[j] == '.' && !visited[1]) {
                        // Found a new region in row 2
                        regions++;
                        visited[1] = true; // Mark row 2 as visited
                        // Move forward until we hit a blocked cell
                        while (j < n && s2[j] == '.') j++;
                    } else if (s2[j] == 'x') {
                        visited[1] = false; // Reset for next region
                    }
                }

                // Count the connections between the two rows
                for (int j = 0; j < n - 1; ++j) {
                    if (s1[j] == '.' && s2[j] == '.') { // They are connected
                        regions--;
                    }
                }

                // If blocking results in exactly 3 regions
                if (regions == 3) {
                    count++;
                }

                // Restore the original state
                if (original1 == '.') s1[i] = '.'; // Restore cell in row 1
                if (original2 == '.') s2[i] = '.'; // Restore cell in row 2
            }
        }

        return count;
    }
};


#endif