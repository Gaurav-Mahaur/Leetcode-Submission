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
    
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* curr = head;
        ListNode* kth=nullptr;
        ListNode* slow=head;
        while(--k && curr)
        {
            curr =curr->next;
        }
        //cout<<curr->val;
        kth = curr;
        while(curr->next)
        {
            curr =curr->next;
            slow = slow->next;
        }
        //cout<<slow->val;
        swap(slow->val,kth->val);
        return head;
        
    }
};