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
        int tot=0;
        ListNode *curr=head;
        while(curr){
            tot++;
            curr=curr->next;
        }
        n=tot-n;
        if(n==0) return head->next;
        n--;
        curr=head;
        while(n--){
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};