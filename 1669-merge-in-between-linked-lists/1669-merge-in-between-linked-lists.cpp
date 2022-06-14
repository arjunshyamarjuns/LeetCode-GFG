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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
         ListNode *temp=list1;
          ListNode *root=list1;
               int count=0,count1=0;
               while(count!=a)
               {
                   temp=temp->next;
                   count++;
               }
               count1=count;
               while(count1!=b)
               {
                  temp=temp->next;
                   count1++;
               }
                temp=temp->next;
        while(count!=1)
        {
          list1=list1->next;
            count--;
        }
        list1->next=list2;
        while(list1->next!=NULL)
            list1=list1->next;
        list1->next=temp;
        return root;
        
    }
};