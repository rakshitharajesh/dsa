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
// this recursive solution will have a time complexity of O(n*m)
// serialize the root and the subRoot and then perform some string matching algiorithm like kmp
// the time complexity becomes O(n + m)
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr)
            return subRoot == nullptr;
        if(root -> val == subRoot -> val)
            if(isSameTree(root, subRoot))
                return true;
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr)
            return subRoot == nullptr;
        if(subRoot == nullptr)
            return false;
        if(root -> val == subRoot -> val){
            return isSameTree(root -> left, subRoot -> left) && isSameTree(root -> right, subRoot -> right);
        }
        return false;
    }
};