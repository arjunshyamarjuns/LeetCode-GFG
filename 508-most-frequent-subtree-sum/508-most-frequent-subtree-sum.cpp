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
     map<int,int> mp;
        int mx;
    int solve(TreeNode* root){
           if(root==NULL) {
                   return 0;
           }
            int left = solve(root->left);
            int right = solve(root->right);
            int sum = left + right + root->val;
            mp[sum]++;
            mx = max(mx, mp[sum]);
            return sum;

            
            
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
            mp.clear();
            mx=INT_MIN;
            vector<int> ans;
            solve(root);
            for(auto i: mp){
                    if(i.second==mx){
                            ans.push_back(i.first);
                    }
            }
            return ans;
        
    }
};