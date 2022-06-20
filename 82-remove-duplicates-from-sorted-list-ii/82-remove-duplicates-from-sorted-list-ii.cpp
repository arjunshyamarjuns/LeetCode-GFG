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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;

        map<int,int> mpp;   //to store frequency of elements in map
        ListNode *p=head;
        while(p!=NULL)
        {
            if(mpp.find(p->val) != mpp.end())
            {
                mpp[p->val]++;
            }
            else
                mpp[p->val]=1;
            p=p->next;
        }
        int i=0;
        for(auto it:mpp)
        {
            if(it.second==1)
            {
                if(i==0)                //to make first element as head
                {
                    head->val=it.first;
                    head->next=NULL;
                    p=head;
                    i++;
                }
                else
                {
                    ListNode *temp= new ListNode();
                    temp->val=it.first;
                    temp->next=NULL;
                    p->next=temp;
                    p=temp;
                }
                    
            }
        }
        if(i==0)    //if every element's frequency is more than 1 return null
            return NULL;
        return head;
        
    }
};