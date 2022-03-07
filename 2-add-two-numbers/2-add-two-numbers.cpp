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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* newhead = new ListNode(-1);
        ListNode* temp = newhead;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry=0;
        while(t1 && t2)
        {
            int sum = t1->val + t2->val + carry;
            if(sum>=10)
            {
                sum  = sum%10;
                carry = 1;
            }
            else
            {
                sum = sum%10;
                carry = 0;
            }
                
            temp->next = new ListNode(sum);
            temp=temp->next;
            t1 = t1->next;
            t2=t2->next;
        }
        while(t1)
        {
            int sum  = carry+t1->val;
            if(sum>=10)
            {
                sum=sum%10;
                carry=1;
            }
            else
            {
                carry=0;
            }
            temp->next = new ListNode(sum);
            temp=temp->next;
            t1=t1->next;
        }
        while(t2)
        {
            int sum  = carry+t2->val;
            if(sum>=10)
            {
                sum=sum%10;
                carry=1;
            }
            else
            {
                carry=0;
            }
            temp->next = new ListNode(sum);
            temp=temp->next;
            t2=t2->next;
        }
        if(carry==1)
        {
            temp->next = new ListNode(1);
        }
        return newhead->next;
         
        
    }
};