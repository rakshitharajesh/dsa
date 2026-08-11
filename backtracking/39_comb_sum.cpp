
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        vector<vector<int>>ans;
        makeCombo(curr, ans, 0, target, candidates);
        return ans;
    }
    void makeCombo(vector<int>& curr, vector<vector<int>>& ans, int ind, int target, vector<int>& candidates){
        if(target < 0 || ind >= candidates.size())return;
        if(target == 0){
            ans.push_back(curr);
         a   return;
        }
        makeCombo(curr, ans, ind+1, target, candidates);
        curr.push_back(candidates[ind]);
        makeCombo(curr, ans, ind, target - candidates[ind], candidates);
        curr.pop_back();
    }
};
