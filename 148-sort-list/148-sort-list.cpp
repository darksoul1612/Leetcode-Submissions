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
    ListNode *middle(ListNode *head){
        ListNode *slow=head, *fast=head;
        while(fast and fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    
    ListNode *merge(ListNode *a, ListNode *b){
        if(a==nullptr) return b;
        else if(b==nullptr) return a;
        
        ListNode *head=nullptr, *tail=nullptr;
        if(a->val > b->val){
            head=b;
            b=b->next;
        }
        else{
            head=a;
            a=a->next;
        }
        
        tail=head;
        
        while(a and b){
            if(a->val > b->val){
                tail->next=b;
                tail=b;
                b=b->next;
            }
            else{
                tail->next=a;
                tail=a;
                a=a->next;
            }
        }
        
        if(a!=nullptr) tail->next=a;
        else tail->next=b;
        
        return head;
    }
    
    ListNode* sortList(ListNode* head) {
              if(head==nullptr || head->next==nullptr) return head;
        
        ListNode *mid=middle(head);
        ListNode *head2 = mid->next;
        
        mid->next=nullptr;
        
        head = sortList(head);
        head2 = sortList(head2);
        
        ListNode *final=merge(head, head2);
        return final;
    }
};