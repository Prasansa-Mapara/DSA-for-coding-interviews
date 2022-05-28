/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0, n2=0;
        ListNode *curr=headA;
        while(curr){
            curr=curr->next;
            n1++;
        }
        curr=headB;
        while(curr){
            curr=curr->next;
            n2++;
        }
        if(n1!=n2){
            if(n1>n2){
                while(n1!=n2){
                    headA=headA->next;
                    n1--;
                }
            }
            else{
                while(n1!=n2){
                    headB=headB->next;
                    n2--;
                }
            }
        }
        while(headA && headB && headA != headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
};