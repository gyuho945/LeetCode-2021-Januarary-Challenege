/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Solution #1 DFS In-Order Traversal
// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(h) height of the tree

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

// Solution #2 BFS using Queue
// Time Complexity: O(n) where n is the number of nodes
// Space Complexity: O(l) max length of elements in a level

class Solution {
    vector<bool> result;
    
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        queue<TreeNode*> q1, q2;
        
        q1.push(original);
        q2.push(cloned);
        
        while(!q1.empty()){
            int len = q1.size();
            
            for(int i = 0; i < len; i++){
                TreeNode *curr1 = q1.front();
                TreeNode *curr2 = q2.front();
                q1.pop();
                q2.pop();
                
                if(curr1 == target)
                    return curr2;
                
                if(curr1->left){
                    q1.push(curr1->left);
                    q2.push(curr2->left);
                }
                
                if(curr1->right){
                    q1.push(curr1->right);
                    q2.push(curr2->right);
                }
                    
            }
        }
        
        return q1.front();
    }
    
};