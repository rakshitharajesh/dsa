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
    TreeNode* findSuccessor(TreeNode* root){
        if(!root)
            return nullptr;
        if(root -> left == nullptr)
            return root;
        return findSuccessor(root -> left);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        if(root -> val > key){
            root -> left = deleteNode(root -> left, key);
        }else if(root -> val < key){
            root -> right = deleteNode(root -> right, key);
        }else{
            // left pointer is null -> return right
            if(root -> left == nullptr){
                if(root -> right == nullptr)
                    return nullptr;
                return root -> right;
            // right pointer is null -> return left
            }else if(root -> right == nullptr)
                return root -> left;
            // the node has both left and right children
            TreeNode* succ = findSuccessor(root -> right);
            int succval = succ -> val;
            root -> right = deleteNode(root -> right, succval);
            root -> val = succval;
        }
        return root;
    }
};