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
    string str_p, str_q;
public:
    void preOrder(TreeNode *root, int sel){
        if(root == NULL){
            if(sel == 1){
                str_p.push_back('-');    
            }
            else{
                str_q.push_back('-');    
            }
            return;
        }
        
        if(sel == 1){
            str_p.push_back((char)root->val);    
        }
        else{
            str_q.push_back((char)root->val);    
        }
        preOrder(root->left, sel);
        preOrder(root->right, sel);
        
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        preOrder(p, 1);
        preOrder(q, 2);
        
        return str_p == str_q;
    }
};