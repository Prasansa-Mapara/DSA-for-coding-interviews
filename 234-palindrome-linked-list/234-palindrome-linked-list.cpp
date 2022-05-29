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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        } //found mid;
        ListNode *prev=NULL, *curr=slow, *nex; //in case of even 
        if(fast) curr=slow->next; //in case of odd, reverse after mid;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        while(prev){ //now check if before mid and after mid are equal;
            if(head->val==prev->val){
                head=head->next;
                prev=prev->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};