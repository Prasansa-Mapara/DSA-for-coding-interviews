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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr=head;
        int cnt=0;
        while(curr){
            cnt++;
            curr=curr->next;
        }
        n=cnt-n;
        if(n==0){
            return head->next;
        }
        curr=head;
        ListNode *prev;
        while(n){
            prev=curr;
            curr=curr->next;     
            n--;
        }
        prev->next=curr->next;
        return head;
    }
};