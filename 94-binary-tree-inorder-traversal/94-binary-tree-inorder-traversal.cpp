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
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int>ans;
        stack<TreeNode* >st;
        TreeNode* node = root;
        while(node!=NULL || !st.empty()) {
            if(node != NULL) 
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                node = st.top();
                ans.push_back(node->val);
                st.pop();
                node = node->right;
            }
        }
        return ans;
    }
};