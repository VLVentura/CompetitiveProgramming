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
    vector<vector<int>> order, rorder;
public:
    void levelOrder(TreeNode *root){
        if(root == NULL){
            return;
        }
        
        TreeNode *delimeter = NULL;
        vector<int> temp;
        
        queue<TreeNode*> Q;
        Q.push(root);
        Q.push(delimeter);
        
        while(!Q.empty()){
            TreeNode *it = Q.front();
            Q.pop();
            
            if(it != delimeter){
                temp.push_back(it->val);
                
                if(it->left != NULL){
                    Q.push(it->left);
                }
                if(it->right != NULL){
                    Q.push(it->right);
                }
            }        
            else{
                order.emplace_back(temp);
                temp.clear();
                if(!Q.empty()){
                    Q.push(delimeter);
                }
            }
        }   
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        levelOrder(root);
        
        copy(order.rbegin(), order.rend(), back_inserter(rorder));
        return rorder;
    }
};