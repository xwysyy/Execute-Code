#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> solve(int &n, string &s) {
        vector<long long> ans(n);
        for (int i = 1; i <= n; ++i) {
            long long res = 0;
            int cnt = 0;
            bool possible = false;
            for (int j = 0; j < n; ++j) {
                if (j < i && s[j] == '0') {
                    cnt++;
                } else if (j >= i && s[j] == '0') {
                    
                }
                if (j < i and s[j] == '1'){
                    if (possible == false){
                         ans[i-1] = -1;
                    } else{
                       
                    }
                   
                }

                 if (j < i && s[j] == '0' and possible == false){

                        
                            
                        
                    
                }

                if ( cnt == i){
                   possible = true;
                 }

                if (possible == true){
                    if(s[j] == '0'){
                        ans[i-1] += j-(j-cnt);
                        cnt--;
                    }
                }

                if (cnt == i){
                   possible = true;
                 }
                
            }

           if (possible == false){
                ans[i-1] = -1;
            }
        }
        return ans;
    }
};


#endif