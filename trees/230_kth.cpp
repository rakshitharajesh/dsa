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
    int k;
    int ans = -1;
    int kthSmallest(TreeNode* root, int k) {
        this -> k = k;
        kth(root);
        return ans;
    }
    void kth(TreeNode* root){
        if(!root)
            return;
        kth(root ->left);
        k--;
        if(k == 0){
            ans = root -> val;
            return;

        }
        kth(root -> right);
    }
};