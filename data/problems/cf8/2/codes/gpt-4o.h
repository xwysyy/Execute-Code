#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    std::string solve(int &n, std::vector<int> &a, std::string &s) {  
        std::unordered_map<int, char> num_to_char;
        std::unordered_map<char, int> char_used;

        for (int i = 0; i < n; ++i) {
            int number = a[i];
            char letter = s[i];

            if (num_to_char.count(number)) {
                if (num_to_char[number] != letter) {
                    return "NO";
                }
            } else {
                if (char_used.count(letter) && char_used[letter] != number) {
                    return "NO";
                }

                num_to_char[number] = letter;
                char_used[letter] = number;
            }
        }
        
        return "YES";
    }
};


#endif