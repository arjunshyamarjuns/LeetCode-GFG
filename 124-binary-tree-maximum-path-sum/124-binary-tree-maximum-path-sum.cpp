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
    int get_path(TreeNode* root , int &maxi)
    {
        if(root==nullptr)
            return 0;
        else
        {
            int lef=get_path(root->left , maxi);
            int rig = get_path(root->right , maxi);
            maxi = max(maxi , max(root->val , max(root->val+lef+rig,max(root->val+lef,root->val+rig))));
            
            return  max(root->val,root->val+max(lef,rig));
        }
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int x=get_path(root , maxi);
        return maxi;
    }
};