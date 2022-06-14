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
class Solution {
public:
    void reorderList(ListNode* head) {
         vector<int> v;
        ListNode* it = head;
        while(it!=0){
            v.push_back(it->val);
            it=it->next;
        }
        int n = v.size();
        int l=0, r=n-1;
        it = head;
        while(l<=r){
            it->val = v[l];
            if(it->next!=0)
            it->next->val = v[r];
            else break;
            l++; r--;
            it=it->next->next;
        }
    }
};