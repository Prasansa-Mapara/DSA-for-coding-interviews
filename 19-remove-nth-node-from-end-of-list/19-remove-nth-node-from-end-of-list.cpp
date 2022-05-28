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
        int cnt=0;
        ListNode *tmp=head;
        while(tmp){
            cnt++;
            tmp=tmp->next;
        }
        int t=cnt-n-1;
        if(t==(-1)){
            return head->next;
        }
        tmp=head;
        while(t){
            tmp=tmp->next;
            t--;
        }
        if(tmp->next) tmp->next=tmp->next->next;
        return head;
    }
};