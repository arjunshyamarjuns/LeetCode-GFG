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
    int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        //A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
        if (root->left && root->left->left == nullptr && root->left->right == nullptr){ 
            sum += root->left->val;  
        }
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return sum;
    }
};