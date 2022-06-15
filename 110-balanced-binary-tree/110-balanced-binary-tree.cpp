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
   int getDepth(TreeNode* root){
if(root==nullptr)return 0;
int left=getDepth(root->left);
int right=getDepth(root->right);
return max(left,right)+1;
}
bool isBalanced(TreeNode* root) {
if(root==nullptr)return true;
int l=getDepth(root->left);
int r=getDepth(root->right);
if(abs(l-r)>1)return false;
bool left=isBalanced(root->left);
bool right=isBalanced(root->right);
return left&&right;
}
};