/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // dp[node].first -> max cost when skipped
    // dp[node].second -> max cost when node is taken
    //unordered_map<TreeNode*, pair<int, int>>dp;
    int rob(TreeNode* root) {
        auto p = solve(root);
        return max(p.first, p.second);
    }
    pair<int, int> solve(TreeNode* root){
        if(!root)
            return {0, 0};
        auto left = solve(root -> left);
        auto right = solve(root -> right);
        // if we skip node -> we can skip or take left / right
        int skip = max(left.first, left.second) + max(right.first, right.second);
        // if we take node -> we have to skip left and right nodes
        int take = left.first + right.first + root -> val;
        return {skip, take};
    }
};