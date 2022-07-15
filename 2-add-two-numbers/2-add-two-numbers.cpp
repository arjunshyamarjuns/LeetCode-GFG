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
class Solution
{
    public:
        ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
        {
            ListNode *ans;
            int sizel1 = 0, sizel2 = 0;
            ListNode *temp = l1;
            while (temp != nullptr) temp = temp->next, sizel1++;
            temp = l2;
            while (temp != nullptr) temp = temp->next, sizel2++;
            if (sizel1 < sizel2)
                swap(l1, l2);
            ans=l1;
            int carry = 0;

            while (l1 != nullptr)
            {
                int num1 = l1->val, num2 = 0;
                if (l2 != nullptr)
                    num2 = l2->val;
                l1->val = (num1 + num2 + carry) % 10;
                carry = (num1 + num2 + carry) / 10;
                temp = l1;
                l1 = l1->next;
                if (l2 != nullptr)
                    l2 = l2->next;
            }
            if (carry == 1)
                temp->next = new ListNode(1);
            return ans;
        }
};