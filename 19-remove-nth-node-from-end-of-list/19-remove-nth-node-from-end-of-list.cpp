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
    
    ListNode* removeHead(ListNode* head){
        int temp=head->next->val;
        head->next->val=head->val;
        head->val=temp;
        
        ListNode *tmp = head->next;
        head->next=head->next->next;
        delete(tmp);
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        if(head->next==nullptr) {
            delete(head);
            return nullptr;
        }
        
        ListNode* slow=head, *fast=head;
        
        for(int i=0; i<n; i++)
            fast=fast->next;
        
        if(fast==nullptr) return removeHead(head);
        
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        
        ListNode *temp=slow->next;
        slow->next=slow->next->next;
        delete(temp);
        
        return head;
    }
};