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
    
    ListNode* reverse(ListNode* head, int n)
    {
        ListNode *curr=head, *next=nullptr, *prev=nullptr;
        for(int i=0; i<n; i++){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        head->next=curr;
        return prev;
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        int n=0;
        ListNode *temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        if(n==0) return head;
        k=k%n;
        if(k==0) return head;
        

        head=reverse(head, n-k);    // reversing starting n-k nodes
        
        ListNode *slow=head;
        ListNode *fast=head;
        for(int i=0; i<k; i++) fast=fast->next;
        
        while(fast and fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        
        slow->next=reverse(slow->next, k);  // reversing last k nodes
        
        head=reverse(head, n);     // reversing full list 
        
        return head;
    }
};