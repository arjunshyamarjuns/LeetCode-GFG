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
        excessCoins_Dfs(root) ;       // this recursive function will return the excess no. of coins for a particular node
        return res;
    }
    int excessCoins_Dfs(TreeNode* root){
        if(!root)       return 0;                   // base case when null is encountered
        int LeftExcess = excessCoins_Dfs(root->left);       // we will get the excess coins from left subtree
        int RighttExcess = excessCoins_Dfs(root->right);    // we will get the excess coins from right subtree
        res+= abs(LeftExcess)+abs(RighttExcess);            //tricy part: the no. of movements will be abs sum of left and right part
            
        return root->val+LeftExcess+RighttExcess-1;     // tricky part: the excess will be this value consider a simple tree with a left node and right node having 0 coins and root having 3 coins u will get it ;) /
        
        
    }
};