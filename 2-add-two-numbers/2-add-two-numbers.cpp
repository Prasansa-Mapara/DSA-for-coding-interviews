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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x=0, sum=(l1->val + l2->val + x)%10;
        x=(l1->val + l2->val + x)/10;
        ListNode *curr=new ListNode(sum), *head=curr;
        l1=l1->next; l2=l2->next;
        while(l1 && l2){
            sum=(l1->val + l2->val + x)%10;
            x=(l1->val + l2->val + x)/10;
            curr->next=new ListNode(sum);
            curr=curr->next;
            l1=l1->next; l2=l2->next;
        }
        while(l1){
            sum=(l1->val + x)%10;
            x=(l1->val + x)/10;
            curr->next=new ListNode(sum);
            curr=curr->next;
            l1=l1->next;
        }
        while(l2){
            sum=(l2->val + x)%10;
            x=(l2->val + x)/10;
            curr->next=new ListNode(sum);
            curr=curr->next;
            l2=l2->next;
        }
        if(x){
            curr->next=new ListNode(x);
            curr=curr->next;
        }
        return head;
    }
};