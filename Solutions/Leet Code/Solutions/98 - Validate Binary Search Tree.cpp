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
    
    bool isBST(TreeNode *root, long neg_inf, long pos_inf){
        if(root == NULL){
            return true;
        }
        if(root->val <= neg_inf || root->val >= pos_inf){
            return false;
        }
    
        return isBST(root->left, neg_inf, root->val) && isBST(root->right, root->val, pos_inf);
    }
    
    bool isValidBST(TreeNode* root) {
        return isBST(root, LONG_MIN, LONG_MAX);
    }
};