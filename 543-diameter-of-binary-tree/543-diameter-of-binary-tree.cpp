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
     int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int dia = 0;
        height(root, dia);
        return dia;
    }
    
    int height(TreeNode* root, int& dia){
        if(!root) return 0;
        int leftH = height(root->left, dia);
        int rightH = height(root->right, dia);
        
        dia = max(dia, leftH+rightH);
        return max(leftH, rightH) + 1;
    }
};