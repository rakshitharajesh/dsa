#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int balance = 0;
        // track the number of open brackets that have been used
        int remaining = n;
        vector<string>ans;
        string curr = "";
        backtrack(balance, remaining, curr, ans);
        return ans;
    }
    void backtrack(int balance, int remaining, string& curr, vector<string>& ans){
        if(balance == 0 && remaining == 0){
            ans.push_back(curr);
            return;
        }
        if(remaining > 0){
            curr += '(';
            backtrack(balance + 1, remaining - 1, curr, ans);
            curr.pop_back();
        }
        if(balance > 0){
            curr += ')';
            backtrack(balance - 1, remaining, curr, ans);
            curr.pop_back();
        }
    }
};