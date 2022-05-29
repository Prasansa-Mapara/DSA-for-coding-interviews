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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hash;
        while(head){
            if(hash.find(head)!=hash.end()){
                return head;
            }
            hash.insert(head);
            head=head->next;
        }
        return NULL;
    }
};