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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int n=0;
        ListNode *curr=head;
        while(curr){
            curr=curr->next;
            n++;
        }
        k%=n;
        if(k==0) return head;
        int t=n-k;
        ListNode *prev;
        curr=head;
        while(t--){
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        prev=curr;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=head;
        return prev;
    }
};