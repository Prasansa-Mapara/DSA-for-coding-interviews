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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //wid constant space;
        ListNode *sol=new ListNode(), *prev=sol;
        while(list1 && list2){
            if(list1->val <= list2->val){
                sol->next=list1;
                list1=list1->next;
            }
            else{
                sol->next=list2;
                list2=list2->next;
            }
            sol=sol->next;
        }
        if(list1){
            sol->next=list1;
        }
        if(list2){
            sol->next=list2;
        }
        return prev->next;
    }
};