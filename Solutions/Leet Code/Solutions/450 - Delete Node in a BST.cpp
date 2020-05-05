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
    int min_element(TreeNode *root){
        if(root == NULL){
            return -1e5;
        }
        if(root->left == NULL){
            return root->val;
        }
        
        return min_element(root->left);
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }
        else if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            if(root->right == NULL && root->left == NULL){
                delete root;
                root = NULL;
            }
            else if(root->right == NULL){
                TreeNode *temp = root;
                root = root->left;
                delete temp;
            }
            else if(root->left == NULL){
                TreeNode *temp = root;
                root = root->right;
                delete temp;
            }
            else{
                int data = min_element(root->right);
                root->val = data;
                root->right = deleteNode(root->right, data);
            }
        }

        return root;
    }
};