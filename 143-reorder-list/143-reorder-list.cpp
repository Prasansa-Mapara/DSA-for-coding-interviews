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
    //instead of creating a copy of list, and then reversing and merging, which will take O(n) space
    //i can do it in O(1) space, by reversing second half of list n then merging;
    void reorderList(ListNode* head) {
        //first find a mid;
        if(!head) return;
        ListNode *slow=head, *fast=head, *prev=NULL;
        while(fast && fast->next){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        if(prev) prev->next=NULL;
        //mid is slow;
        ListNode *curr=slow, *nxt;
        prev=NULL;
        
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        ListNode *l1=head, *l2=prev;
        if(l1==l2) return;
        curr=new ListNode();
        while(l1 && l2){
            curr->next=l1;
            l1=l1->next;
            curr=curr->next;
            curr->next=l2;
            l2=l2->next;
            curr=curr->next;
        }
        if(l1) curr->next=l1;
        if(l2) curr->next=l2;
    
    }
};