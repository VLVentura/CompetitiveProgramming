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

Symmetric tree:
    1
   / \
  2   2
 / \ / \
3  4 4  3

Not a symmetric tree:
    1
   / \
  2   2
   \   \
   3    3

*/

class Solution {
    bool check(TreeNode *left, TreeNode *right){
        if(left == NULL && right == NULL){
            return true;
        }
        else if(left != NULL && right != NULL){
            return (left->val == right->val) && check(left->left, right->right) && check(left->right, right->left);
        }
        
        return false;
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || check(root->left, root->right);
    }
};