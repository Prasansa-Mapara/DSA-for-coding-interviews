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
    void reorderList(ListNode* head) {
        int n=0; 
        ListNode *curr=new ListNode(), *tmp=head, *tmp2=curr;
        while(tmp){
            curr->next=new ListNode(tmp->val);
            curr=curr->next;
            tmp=tmp->next;
            n++;
        }
        ListNode *head2=tmp2->next;
        //now reverse this second list;
        ListNode *prev=NULL, *nxt;
        curr=head2;
        while(curr){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        
        head2=prev;
        tmp=head; tmp2=head2;
        curr=new ListNode();
        ListNode *sol=curr;
        
        while(n){
            curr->next=tmp;
            tmp=tmp->next;
            n--;
            curr=curr->next;
            if(n){
                curr->next=tmp2;
                tmp2=tmp2->next;
                n--;
                curr=curr->next;
            }
        }
        curr->next=NULL;
        //head= sol->next;
    }
};