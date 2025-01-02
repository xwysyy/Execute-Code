#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, std::vector<int> &a, std::string &s) {
        std::unordered_map<int, char> map_num_to_char;
        
        for (int i = 0; i < n; ++i) {
            int num = a[i];
            char char_in_s = s[i];
            
            if (map_num_to_char.find(num) != map_num_to_char.end()) {
                // If there's already a mapping, it must match the current character in s
                if (map_num_to_char[num] != char_in_s) {
                    return "NO";
                }
            } else {
                // Create a new mapping
                map_num_to_char[num] = char_in_s;
            }
        }
        
        return "YES";
    }
};


#endif