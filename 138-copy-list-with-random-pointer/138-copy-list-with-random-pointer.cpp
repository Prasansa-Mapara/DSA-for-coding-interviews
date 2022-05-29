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
        unordered_map<Node*, Node*> hash;
        Node *curr=head;
        if(!curr) return NULL;
        hash[curr]=new Node(curr->val);
        while(curr){
            Node *a=curr->next, *b=curr->random;
            if(a && hash.find(a)==hash.end()){
                hash[a]=new Node(a->val);
            }
            else if(!a) hash[a]=NULL;
            if(b && hash.find(b)==hash.end()){
                hash[b]=new Node(b->val);
            }
            else if(!b) hash[b]=NULL;
            hash[curr]->next=hash[a];
            hash[curr]->random=hash[b];
            curr=curr->next;
        }
        return hash[head];
    }
};