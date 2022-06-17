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
    int solve(TreeNode* root,int &maxi,int &mini,int &sum){
    if(root == NULL)
        return 0;
    
    int leftMaxi,leftMini,rightMaxi,rightMini;
    leftMaxi = rightMaxi = INT_MIN;
    leftMini = rightMini = INT_MAX;
    int leftSum = solve(root->left,leftMaxi,leftMini,sum);
    int rightSum = solve(root->right,rightMaxi,rightMini,sum);
    
    int total = leftSum + rightSum + root -> val;
    
    if(leftMaxi < root -> val and root -> val < rightMini){
        sum = max(sum,total);
        maxi = max(root -> val,rightMaxi);
        mini = min(root -> val,leftMini);
    }else{
        maxi = INT_MAX;
        mini = INT_MIN;
    }
    
    return total;
    
}
int maxSumBST(TreeNode* root) {
    int sum = 0,mini = INT_MIN,maxi = INT_MAX;
    solve(root,maxi,mini,sum);
    return sum;
}
};