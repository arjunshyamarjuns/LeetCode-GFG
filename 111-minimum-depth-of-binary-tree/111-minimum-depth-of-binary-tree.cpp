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
      void dfs(TreeNode* root,int i,int &min_val)
    {
        if(!(root)) return;
        if(!(root->left) && !(root->right)){
            min_val = min(min_val,i); 
        }
        dfs(root->left,i+1,min_val);
        dfs(root->right,i+1,min_val);
    }
    int minDepth(TreeNode* root) {
        if(!(root)) return 0;
        int min_val = INT_MAX;
        dfs(root,1,min_val);
        return min_val;
    }
};