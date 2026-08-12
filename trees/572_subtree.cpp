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
    vector<int>LPS(string p){
        int i = 1;
        int j = 0;
        int m = p.length();
        vector<int>lps(m, 0);
        while(i < m){
            if(p[i] == p[j]){
                j++;
                lps[i] = j;
                i++;
            }else{
                if(j == 0){
                    lps[i] = 0;
                    i++;
                }else{
                    j = lps[j - 1];
                }
            }
        }
        return lps;
    }
    string serialize(TreeNode* root){
        if(root == nullptr)
            return "#";
        
        string s = '.' + to_string(root -> val) + '.';
        s += serialize(root -> left) + serialize(root -> right);
        return s;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot){
        string s = serialize(root);
        string p = serialize(subRoot);
        vector<int>lps = LPS(p);
        int i = 0;int j = 0;
        int n = s.length();
        while(i < n){
            if(s[i] == p[j]){
                i++;j++;
            }else{
                // not a match
                if(j == 0){
                    i++;
                }else{
                    j = lps[j - 1];
                }
            }
            if(j == p.length())
                return true;
        }
        return false;

    }
// this recursive solution will have a time complexity of O(n*m)
// serialize the root and the subRoot and then perform some string matching algiorithm like kmp
// the time complexity becomes O(n + m)
    bool isSubtree_(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr)
            return subRoot == nullptr;
        if(root -> val == subRoot -> val)
            if(isSameTree(root, subRoot))
                return true;
        return isSubtree_(root -> left, subRoot) || isSubtree_(root -> right, subRoot);
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