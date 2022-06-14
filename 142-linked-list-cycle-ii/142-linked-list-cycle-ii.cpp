/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head,*fast=head;
        while (true) {
            if (fast==NULL||fast->next==NULL) return NULL;
            slow=slow->next;
            fast=fast->next->next;
            if (slow==fast) break;
        }
        fast=head;
        while (true) {
            if (slow==fast) break;
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};