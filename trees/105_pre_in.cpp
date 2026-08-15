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
    int index = 0;
    // index of each element in the inorder array
    unordered_map<int, int>indexInorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        // first element of the preorder traversal is the root
        for(int i = 0 ; i < n ; i++){
            indexInorder[inorder[i]] = i;
        }
        TreeNode* root = build(preorder, inorder, 0, n - 1);
        return root;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right){
        if(left > right)
            return nullptr;
        TreeNode* node = new TreeNode(preorder[index]);
        //int i = find(inorder.begin(), inorder.end(), preorder[index]) - inorder.begin();
        int i = indexInorder[preorder[index]];
        index += 1;
        node -> left = build(preorder, inorder, left, i - 1);
        node -> right = build(preorder, inorder, i + 1, right);
        return node;
    }
};