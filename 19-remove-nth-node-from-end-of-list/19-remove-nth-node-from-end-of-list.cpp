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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head==nullptr)
        {
            return nullptr;
        }
        if(head->next==nullptr)
        {
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        int k = n;
        while(k--)
        {
            fast = fast->next;
        }
        if(fast==nullptr)
        {
            return head->next;
        }
        ListNode* prev = nullptr;
        while(fast!=nullptr)
        {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        //cout<<slow->val<<endl;
        delete(slow);
        return head;
        
    }
};