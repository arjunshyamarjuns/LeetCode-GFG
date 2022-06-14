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
    bool isPalindrome(ListNode* head) {
          ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *curr=slow;
        ListNode *prev=NULL;
        while(curr!=NULL){
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
      ListNode *ptr1=head;
      ListNode *ptr2=prev;
      while(ptr1!=NULL && ptr2!=NULL){
          if(ptr1->val!=ptr2->val)
            return false;
          ptr1=ptr1->next;
          ptr2=ptr2->next;
      }
      return true;
    }
};