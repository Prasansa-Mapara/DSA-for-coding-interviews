/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *curr=head;
        if(!curr) return NULL;
        //for next ptrs;
        while(curr){
            Node *tmp=new Node(curr->val);
            tmp->next=curr->next;
            curr->next=tmp;
            curr=curr->next->next;
        }
        //for random ptrs;
        curr=head;
        while(curr){
            if(curr->random){
                curr->next->random=curr->random->next;
            }
            else{
                curr->next->random=NULL;
            }
            curr=curr->next->next;
        }
        //getting final ans;
        Node *sol=head, *ncurr=head->next;
        sol=sol->next;
        curr=head;
        while(curr){
            curr->next=ncurr->next;
            if(curr->next){
                ncurr->next=ncurr->next->next;
            }
            else{
                ncurr->next=NULL;
            }
            curr=curr->next;
            ncurr=ncurr->next;
        }
        return sol;
    }
};