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
    
    ListNode* merge(ListNode *a, ListNode *b){
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
        else if(b!=nullptr) tail->next=b;
        
        return head;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()<1) return nullptr;
        if(lists.size()==1) return lists[0];
        
        ListNode *head=merge(lists[0], lists[1]);
        for(int i=2; i<lists.size(); i++){
            head=merge(head, lists[i]);
        }
        
        return head;
    }
};