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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
          if(root==NULL) 
              return  root =new TreeNode(val);
    
    TreeNode* temp=root,*temp2=root;

        while(temp!=NULL)
        {
        
        if(temp->val > val)
        {
            temp2=temp;
             cout<<temp->val;
            temp=temp->left;
        }
        else
        {
            temp2=temp;
            temp=temp->right;
        }
    }

    TreeNode *temp1=new TreeNode(val);
    
    if(temp2->val > val)
    {
       temp2->left=temp1;            
    }
    else
    {
        temp2->right=temp1;
    }
    
    return root;
    
}
    
};