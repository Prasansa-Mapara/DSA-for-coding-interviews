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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        int tmp=k, tmp2=k;
        ListNode *l=head;
        while(l && tmp2){
            l=l->next;
            tmp2--;
        }
        if(tmp2) return head;
        ListNode *prev=NULL, *curr=head, *next;
        while(curr && tmp--){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head->next=reverseKGroup(curr, k);
        return prev;
    }
};