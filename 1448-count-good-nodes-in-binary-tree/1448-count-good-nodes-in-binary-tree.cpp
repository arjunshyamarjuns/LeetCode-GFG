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
   int ans=0;
void solve(TreeNode* root, int max1){
if(root==NULL)
return;
if(root->val >= max1){
//cout<val<<endl;
ans++;
}
max1=max(root->val,max1);
solve(root->left,max1);
solve(root->right,max1);
}
int goodNodes(TreeNode* root) {
solve(root,INT_MIN);
return ans;
}
};