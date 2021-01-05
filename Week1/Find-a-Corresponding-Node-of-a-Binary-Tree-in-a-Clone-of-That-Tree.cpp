/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode *result;
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        DFS(original, cloned, target);
        
        return result;
    }
    
    void DFS(TreeNode *root, TreeNode *cloned, TreeNode *target){
        if(!root)
            return;
        
        if(root == target){
            result = cloned;
            return;
        }
            
        DFS(root->left, cloned->left, target);
        DFS(root->right, cloned->right, target);
        
        
    }
};