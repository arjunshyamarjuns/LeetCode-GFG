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
     int res;
    int distributeCoins(TreeNode* root) {
        res = 0;
        excessCoins_Dfs(root) ;
        return res;
    }
    int excessCoins_Dfs(TreeNode* root){
        if(!root)       
            return 0;
        int LeftExcess = excessCoins_Dfs(root->left);       
        int RighttExcess = excessCoins_Dfs(root->right); 
        res+= abs(LeftExcess)+abs(RighttExcess);           
            
        return root->val+LeftExcess+RighttExcess-1;
        
        
    }
};