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
    bool checkBST(TreeNode* root, long mn, long mx)
{
    if(root==NULL)
        return true;
    
    if(root->val>mn && root->val<mx)
    {
        return checkBST(root->left,mn,root->val) && checkBST(root->right,root->val,mx);
    }
    else{
        return false;
    }
}

bool isValidBST(TreeNode* root) {
    
    return checkBST(root,LONG_MIN,LONG_MAX);       
}
};