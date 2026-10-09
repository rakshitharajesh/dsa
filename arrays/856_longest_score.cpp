#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int balance = 0;
        for(int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            if(c == '('){
                balance++;
            }else{
                balance--;
                if(s[i - 1] == '('){
                    score += (1 << balance);
                }
            }
        }
        return score;
    }
};