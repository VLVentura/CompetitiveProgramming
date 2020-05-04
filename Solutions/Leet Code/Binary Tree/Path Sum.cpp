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
    //if we want a path to that leaf, uncomment the lines who push_back to this vector
    //vector<int> path; 
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        }
        
        //leaf
        if(root->left == NULL && root->right == NULL){
            if(sum == root->val){
                //order.push_back(root->data);
                return true;
            }
        }
        
        if(hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val)){
            //order.push_back(root->data);
            return true;
        }
        
        return false;
    }
};