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
    
    ListNode *add(ListNode *head1, ListNode* head2, int carry){
        if(head1==nullptr and head2==nullptr){
            if(carry){
                ListNode *temp=new ListNode(carry);
                return temp;
            }
            else return nullptr;
        }
        
        ListNode *temp;
        
        if(head1 and head2){
            int val=head1->val + head2->val + carry;
            carry=val/10;
             temp = new ListNode(val%10, add(head1->next, head2->next, carry));
        }
        else if(head1){
            int val=head1->val+carry;
            carry=val/10;
            temp=new ListNode(val%10, add(head1->next, head2, carry));
        }
        else if(head2){
            int val=head2->val+carry;
            carry=val/10;
            temp=new ListNode(val%10, add(head1, head2->next, carry));
        }
        
        return temp;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};