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
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if(root == nullptr)
            return new TreeNode(val);
        if(root -> val < val){
            root -> right = insertIntoBST(root -> right, val);
        }else{
            root -> left = insertIntoBST(root -> left, val);
        }
        return root;
    }
    TreeNode* insertIntoBST_(TreeNode* root, int val) {
        insert(root, val);
        if(root == nullptr)
            return new TreeNode(val);
        return root;
    }
    void insert(TreeNode* root, int val){
        if(!root)
            return;
        if(root -> val > val){
            if(root -> left == nullptr){
                root -> left = new TreeNode(val);
                return;
            }else{
                insert(root -> left, val);
            }
        }else{
            if(root -> right == nullptr){
                root -> right = new TreeNode(val);
                return;
            }else{
                insert(root -> right, val);
            }
        }
    }
    
};