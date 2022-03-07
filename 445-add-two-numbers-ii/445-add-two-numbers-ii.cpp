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
    ListNode* reverselist(ListNode* &head)
    {
        if(head==nullptr)
        {
            return nullptr;
        }
        ListNode* curr = head;
        ListNode* prev=nullptr;
        ListNode* nextptr;
        
        while(curr)
        {
            nextptr = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = nextptr;
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* list1 = reverselist(l1);
        ListNode* list2 = reverselist(l2);
        ListNode* t1 = list1;
        ListNode* t2 = list2;
       // return t2;
        ListNode* newhead = new ListNode(-1);
        ListNode* temp = newhead;
        int carry=0;
        while(t1 && t2)
        {
            int sum = t1->val + t2->val + carry;
            
            if(sum>=10)
            {
                sum = sum%10;
                carry = 1;
            }
            else
            {
                carry=0;
                sum = sum%10;
            }
            temp->next = new ListNode(sum);
            temp=temp->next;
            t1=t1->next;
            t2=t2->next;
        }
        while(t1)
        {
            int sum = t1->val+carry;
            
            if(sum>=10)
            {
                sum = sum%10;
                carry = 1;
            }
            else
            {
                carry=0;
                sum = sum%10;
            }
            temp->next = new ListNode(sum);
            temp=temp->next;
            t1=t1->next;
           
        }
        while(t2)
        {
            int sum = t2->val+carry;
            
            if(sum>=10)
            {
                sum = sum%10;
                carry = 1;
            }
            else
            {
                carry=0;
                sum = sum%10;
            }
            temp->next = new ListNode(sum);
            temp=temp->next;
            t2=t2->next;
            //t2=t2->next;
        }
        if(carry==1)
        {
            temp->next = new ListNode(1);   
        }
        
        ListNode* finallist = reverselist(newhead->next);
        
        return finallist;
        
    }
};