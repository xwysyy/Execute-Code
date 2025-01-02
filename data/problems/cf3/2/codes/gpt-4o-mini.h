#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string solve(int &n, string &s1, string &s2) {
        bool canReach1 = s1[0] == '0'; // can reach (1,1)
        bool canReach2 = s2[0] == '0'; // can reach (2,1)
        
        for (int i = 0; i < n - 1; i++) {
            bool newCanReach1 = false;
            bool newCanReach2 = false;
            
            // If we can reach (1, i)
            if (canReach1) {
                // Move to (1,i+1)
                if (s1[i + 1] == '0') 
                    newCanReach1 = true;
                // Move to (2,i+1)
                if (s2[i + 1] == '0') 
                    newCanReach2 = true;
            }
            // If we can reach (2, i)
            if (canReach2) {
                // Move to (1,i+1)
                if (s1[i + 1] == '0') 
                    newCanReach1 = true;
                // Move to (2,i+1)
                if (s2[i + 1] == '0') 
                    newCanReach2 = true;
            }
            
            canReach1 = newCanReach1;
            canReach2 = newCanReach2;
        }
        
        // If we can reach (2, n)
        if (canReach2) 
            return "YES";
        return "NO";
    }
};


#endif