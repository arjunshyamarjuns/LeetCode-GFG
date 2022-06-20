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
   map<int,bool> m; //value and freq
    
    bool findTarget(TreeNode* root, int k) 
    {
        if (!root)
            return false;
        
        if (m.count(k-(root->val)) > 0)
            return true;
        
        m[root->val] = true;
        
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
    
};