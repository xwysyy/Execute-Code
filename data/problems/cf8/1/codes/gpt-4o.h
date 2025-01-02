#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, std::vector<int> &a, std::string &s) {
        // map to store previously seen mappings from number -> character
        std::unordered_map<int, char> map;
        
        for (int i = 0; i < n; ++i) {
            int number = a[i];
            char letter = s[i];
            
            // if this number is not mapped yet
            if (map.find(number) == map.end()) {
                // map it to the current character
                map[number] = letter;
            } else {
                // if it's already mapped, check for consistency
                if (map[number] != letter) {
                    return "NO"; // inconsistent mapping found
                }
            }
        }
        
        return "YES";  // if no inconsistencies found
    }
};


#endif