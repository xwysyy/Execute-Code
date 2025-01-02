#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, string &s, vector<int> &a) {
        int totalSavedMagazines = 0;
        int currSavedMagazines = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') { // If there's a lid at this position
                int potentialSave = currSavedMagazines + a[i]; // If we cover this box and previous covered boxes
                totalSavedMagazines = std::max(totalSavedMagazines, potentialSave);
                currSavedMagazines += a[i]; // Add the current box to the running total
            }
            // If there's no lid, we do nothing, just prepare for the next iteration
        }

        return totalSavedMagazines;
    }
};


#endif