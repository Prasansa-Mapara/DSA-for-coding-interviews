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
        //using one-pass;
        
        ListNode *fast=new ListNode(), *slow=fast, *sol=fast;
        fast->next=head;
        int i=n+1;
        while(i--){
            fast=fast->next;
        }
        while(fast){ //when fast is pointing to null, slow will be pointing just before the node to be deleted;
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return sol->next;
    }
};