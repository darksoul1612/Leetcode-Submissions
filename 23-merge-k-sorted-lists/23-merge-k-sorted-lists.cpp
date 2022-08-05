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
    
    class compare{
        public: 
        bool operator()(ListNode *a, ListNode *b){
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()<1) return nullptr;
        if(lists.size()==1) return lists[0];
        
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode *head=nullptr, *tail=nullptr;
        
        int n=lists.size();
        for(auto x: lists){
            
            if(x!=NULL)
            pq.push(x);
        }
        if(!pq.empty())
        {
            head=pq.top();
        pq.pop();
        
        tail=head;
        if(tail->next) pq.push(tail->next);
        }
        
        while(!pq.empty()){
            tail->next=pq.top();
            pq.pop();
            tail=tail->next;
            if(tail->next) pq.push(tail->next);
        }
        
        return head;
    }
};