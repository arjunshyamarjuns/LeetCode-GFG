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
  bool dfs(TreeNode* root1, TreeNode* root2) {
    if (!root1 && !root2)
        return true;
    
    if (!root1 || !root2)
        return false;
    
    return root1->val == root2->val && dfs(root1->left, root2->left) && dfs(root1->right, root2->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root)
        return false;
    
    if (!subRoot)
        return true;
          
    return dfs(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}
};