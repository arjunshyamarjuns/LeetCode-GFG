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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
          ListNode *curr =  head;
        while(n-->0 && curr!=nullptr)
         curr = curr->next; 
        
        if(curr == nullptr) 
            return head->next;
        
        ListNode *slow = head;
        for(curr= curr;curr->next!=nullptr;curr = curr->next)
          slow = slow->next; 
        ListNode *it = slow->next;
        slow->next =slow->next->next;
		delete(it);
        return head; 
    }
};