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
    ListNode* reverse(ListNode* head, int k){
        if(!head)
            return NULL;
        ListNode* prev = NULL;
        ListNode* nxt = head;
        ListNode* end = head;
        int K = k;
        while(K-- && head){
            nxt = nxt->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        
        if(K != -1){
            // last section reversed
            return reverse(prev, k-K-1);
        }
        else{
            end->next = reverse(nxt, k);
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverse(head, k);
    }
};