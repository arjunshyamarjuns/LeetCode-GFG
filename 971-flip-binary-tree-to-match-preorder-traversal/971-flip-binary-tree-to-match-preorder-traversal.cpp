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
    vector<int> flip;
    bool failure;
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        this->failure = false;
        helper(root, voyage);
        if (this->failure){return {-1};}
        return this->flip;
    }
    void helper(TreeNode* root, vector<int>& voyage){
        if (root == nullptr){
            if (voyage.empty()){return;}
            fail();
            return;
        }
        if (root->val != voyage.front()){
            fail();
            return;
        }
        voyage.erase(voyage.begin(), voyage.begin() + 1);
        // root->left:
        if (root->left == nullptr && root->right == nullptr){
            if (voyage.empty()){return;}
            fail();
            return;
        }
        else if (root->left == nullptr && root->right != nullptr){
            if (root->right->val != voyage.front()){
                fail();
                return;
            }
            helper(root->right, voyage);
        }
        else if (root->left != nullptr && root->right == nullptr){
            if (root->left->val != voyage.front()){
                fail();
                return;
            }
            helper(root->left, voyage);
        }
        else{// so, root->left != nullptr && root->right != nullptr
            if (root->left->val == voyage.front()){
                int right_index = -1;
                for (int i = 1; i < voyage.size(); i++){
                    if (voyage[i] == root->right->val){
                        right_index = i;
                        break;
                    }
                }
                if (right_index == -1){
                    fail();
                    return;
                }
                vector<int> left_voyage = vector<int>(voyage.begin(), voyage.begin() + right_index);
                vector<int> right_voyage = vector<int>(voyage.begin() + right_index, voyage.end());
                helper(root->left, left_voyage);
                helper(root->right, right_voyage);
            }
            else{
                int left_index = -1;
                this->flip.push_back(root->val);
                for (int i = 0; i < voyage.size(); i++){
                    if (voyage[i] == root->left->val){
                        left_index = i;
                        break;
                    }
                }
                if (left_index == -1){
                    fail();
                    return;
                }
                vector<int> left_voyage = vector<int>(voyage.begin() + left_index, voyage.end());
                vector<int> right_voyage = vector<int>(voyage.begin(), voyage.begin() + left_index);
                helper(root->left, left_voyage);
                helper(root->right, right_voyage);
            }
        }
    }
    
    void fail(){
        this->failure = true;
        this->flip = {-1};
    } 
    
    void print(vector<int> vi){
        printf("[");
        for (int i: vi){printf("%d, ", i);}
        printf("]\n");
    }
};