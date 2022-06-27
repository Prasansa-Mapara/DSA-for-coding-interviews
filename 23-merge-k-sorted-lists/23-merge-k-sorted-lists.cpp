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
    struct cmp{
        bool operator()(ListNode *a, ListNode* b){
            return a->val > b->val;
        }  
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        ListNode *curr=new ListNode(), *sol=curr;
        for(auto l: lists){
            if(l) pq.push(l);
        }
        while(pq.size()){
            ListNode *tmp=pq.top();
            pq.pop();
            curr->next=tmp;
            curr=curr->next;
            if(tmp->next) pq.push(tmp->next);
        }
        if(sol) return sol->next;
        return sol;
    }
};