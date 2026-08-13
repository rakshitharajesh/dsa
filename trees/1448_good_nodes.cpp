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
    int goodNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return count(root, root -> val);
    }
    int count(TreeNode* root, int maxVal){
        if(root == nullptr) 
            return 0;
        if(maxVal > root -> val){
            return count(root -> left, maxVal) + count(root -> right, maxVal);
        }
        return count(root -> left, root -> val) + count(root -> right, root -> val) + 1;
        
    }
};