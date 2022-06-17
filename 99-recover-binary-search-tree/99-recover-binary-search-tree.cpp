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
    vector<int> v;
int i =0;
void inorder1(TreeNode* T)
{
    if(!T) return;
    inorder1(T->left);
    v.push_back(T->val);
    inorder1(T->right);
}

void inorder2(TreeNode* T)
{
    if(!T) return;
    inorder2(T->left);
    T->val = v[i];
    i++;
    inorder2(T->right);
}
void recoverTree(TreeNode* root) {
    
    inorder1(root);
    sort(v.begin(), v.end());
    inorder2(root);
}
};