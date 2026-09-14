#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int n = INT_MAX;
        for(string s : strs)    
            n = min(n, (int)s.size());
        for(int i = 0 ; i < n ; i++){
            char c = strs[0][i];
            bool valid = true;
            for(string s : strs){
                if(c != s[i]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                prefix += c;
            }
            if(!valid)
                return prefix;
        }
        return prefix;
    }
};