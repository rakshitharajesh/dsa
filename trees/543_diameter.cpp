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
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxDiameter;
    }
    // this function will return the maximum branch height (either the left branch
    // or the right branch
    int height(TreeNode* root){
        if(!root)
            return 0;
        int h = 0;
        int left = 0;
        int right = 0;
        if(root -> left){
            left = height(root -> left);
        }
        if(root -> right){
            right = height(root -> right);
        }
        h = max(right, left) + 1;
        maxDiameter = max(maxDiameter, left + right);
        return h;
    }
    
    
};