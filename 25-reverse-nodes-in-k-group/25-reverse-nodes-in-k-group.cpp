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
        ListNode *a=head; int b=k;
        while(b--){
            if(a) a=a->next;
            else return head;
        }
        ListNode *prev=NULL, *curr=head, *nex;
        int tmp=k;
        while(tmp-- && curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        head->next=reverseKGroup(curr, k);
        return prev;
    }
};