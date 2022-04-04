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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        ListNode *curr=head, *tmp=head;
        while(curr){
            curr=curr->next;
            n++;
        } 
        curr=head;
        int i=k;
        while(--i){
            curr=curr->next;
        }
        tmp=head;
        int j=n-k;
        while(j--){
            tmp=tmp->next;
        }
        swap(curr->val, tmp->val);
        return head;
    }
};