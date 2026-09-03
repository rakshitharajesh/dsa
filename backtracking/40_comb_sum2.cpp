#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this -> n = candidates.size();
        // sort the array so we can avoid picking duplicates
        sort(candidates.begin(), candidates.end());
        vector<int>curr;
        vector<vector<int>>ans;
        backtrack(candidates, curr, ans, 0, target);
        return ans;
    }
    void backtrack(vector<int>& candidates, vector<int>& curr, vector<vector<int>>& ans, int index, int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        if(index == n)
            return;
        for(int i = index ; i < n ; i++){        
            // ignore the same element at the same recursion level
            if(i > index && candidates[i] == candidates[i - 1])
                continue;
            if(candidates[i] > target) 
                break;
            curr.push_back(candidates[i]);
            backtrack(candidates, curr, ans, i + 1, target - candidates[i]);
            curr.pop_back();
        }
    }
};