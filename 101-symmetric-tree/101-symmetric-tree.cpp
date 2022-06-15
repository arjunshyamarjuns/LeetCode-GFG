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
   bool compareNode(TreeNode *left, TreeNode *right) {
        if(left == nullptr && right == nullptr) {
            return true;
        } else if(left != nullptr && right != nullptr) {
            if(left->val == right->val) {
                return compareNode(left->right, right->left) 
                    && compareNode(left->left, right->right);
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return true;
        } else {
            return compareNode(root->left, root->right);
        }
    }
};