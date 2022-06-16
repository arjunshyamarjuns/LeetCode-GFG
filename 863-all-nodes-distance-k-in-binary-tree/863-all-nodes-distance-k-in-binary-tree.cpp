/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<int> res;

void Node_at_depth_k(TreeNode *root, int k)
{
    if (root == NULL || k < 0   )
    {
        return;
    }
    if (k == 0)
    {
        res.push_back(root->val);
        return;
    }
    Node_at_depth_k(root->left, k - 1);
    Node_at_depth_k(root->right, k - 1);
}

// return distance , -1 -> not found

int helper(TreeNode *root, TreeNode *target, int k)
{
    if (root == NULL)
    {
        return -1; // node not found
    }

    if (root->val == target->val)
    {
        Node_at_depth_k(root, k);
        return 0; // dis fron root to root == 0;
    }

    int ld = helper(root->left, target, k);
    if (ld != -1)
    {
        if (ld + 1 == k)
        {
            res.push_back(root->val);
        }
        else
        {
            Node_at_depth_k(root->right, k - ld - 2);
        }
        return ld + 1;
    }
    int rd = helper(root->right, target, k);
    if (rd != -1)
    {
        if (rd + 1 == k)
        {
            res.push_back(root->val);
        }
        else
        {
            Node_at_depth_k(root->left, k - rd - 2);
        }
        return rd + 1;
    }
    return -1;
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    helper(root, target, k);
    return res;
}

};