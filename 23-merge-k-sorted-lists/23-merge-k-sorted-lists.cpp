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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if(lists.size()==0)
        {
            return nullptr;
        }
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
            {
            pq.push({lists[i]->val,lists[i]});
            }
        }
        ListNode* newhead = new ListNode(-1);
        ListNode* temp = newhead;
        
        while(!pq.empty())
        {
            pair<int,ListNode*>t = pq.top();
            pq.pop();
            
            temp->next = new ListNode(t.first);
            temp= temp->next;
            
            if(t.second->next!=nullptr)
            {
                pq.push({t.second->next->val,t.second->next});
            }
        }
        return newhead->next;
    }
};