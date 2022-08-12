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
    
//     bool isBst(TreeNode* root, int min, int max){
//         if(root==nullptr) return true;
        
//       return  ( (root->val > min and root->val < max) and isBst(root->left, min, root->val) and isBst(root->right, root->val, max) );
//     }
    TreeNode *prev=nullptr;
    bool isValidBST(TreeNode* root) {
        
        // return isBst(root, INT_MIN, INT_MAX);
        
        if(root==nullptr) return true;
        
        if(!isValidBST(root->left)) return false;
        if(prev and root->val<=prev->val) return false;
        prev=root;
        
        return isValidBST(root->right);
    }
};