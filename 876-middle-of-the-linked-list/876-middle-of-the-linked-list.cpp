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
    ListNode* middleNode(ListNode* head) {
        int n=0;
        ListNode *curr=head;
        while(curr){
            curr=curr->next;
            n++;
        }
        int req=n/2, i=0;
        curr=head;
        while(i<=req){
            if(i==req){
                return curr;
            }
            curr=curr->next;
            i++;
        }
        return NULL;
    }
};