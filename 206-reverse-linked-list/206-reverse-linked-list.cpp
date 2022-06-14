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
    ListNode* reverseList(ListNode* head) {
       ListNode* current = head;
    ListNode* previous = NULL;
    
    while(current != NULL){
        
        ListNode* n = current->next;//to store the current node 
        current->next = previous; //next of current link to the previous
        previous = current; 
        current = n;
    }
    
    return previous;
    }
};