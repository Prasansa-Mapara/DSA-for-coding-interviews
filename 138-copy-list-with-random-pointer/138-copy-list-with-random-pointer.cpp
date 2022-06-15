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
        //O(n) space will be maintaining a hash;
        //O(1) space solution:
        
        if(!head) return head;
        Node *curr=head;
        
        while(curr){
            Node *tmp=new Node(curr->val); 
            tmp->next=curr->next; //insert a new node(copied node) next to the current node;
            curr->next=tmp;
            curr=tmp->next;
        }
        
        curr=head;
        while(curr){
            Node *tmp=curr->next; //pointing to the copied node;
            if(curr->random){
                tmp->random=curr->random->next; //random ptrs;
            }
            curr=tmp->next;
        }
        
        //dismantling new and old nodes;
        curr=head; 
        Node *sol=curr->next;
        while(curr){
            Node *tmp=curr->next;
            curr->next=tmp->next;
            curr=curr->next;
            if(curr)tmp->next=curr->next;
            else tmp->next=NULL;
            tmp=tmp->next;
        }
        
        return sol;
    }
};