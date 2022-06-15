/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<TreeNode*> nodes;
        void search(TreeNode* root,int val){
                if(root==NULL){
                        return;
                }
                if(root->val==val){
                        nodes.push_back(root);
                }
                search(root->left,val);
                search(root->right,val);
        }
    bool solve(ListNode* head, TreeNode* root){
            if( head==NULL){
                    return true;
            }
            if(root==NULL && head!=NULL){
                    return false;
            }
            if(root->val==head->val){
                    
                            
                    
                    bool l1=solve(head->next,root->left);
                    bool r1=solve(head->next,root->right);
                    if(l1==true || r1==true){
                            return true;
                    }
                    else{
                            return false;
                    }
            }
            return false;
           
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
            nodes.clear();
            search(root,head->val);
            for(auto i: nodes){
                    if(solve(head,i)){
                            return true;
                    }
            }
            return false;
        
    }
};