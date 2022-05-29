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
    //explanation of why this algo works is given in notes :)
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        bool flag=0;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                flag=1; break;
            }
        }
        if(!flag) return NULL;
        while(head != slow){
            head=head->next;
            slow=slow->next;
        }
        return slow;
    }
};