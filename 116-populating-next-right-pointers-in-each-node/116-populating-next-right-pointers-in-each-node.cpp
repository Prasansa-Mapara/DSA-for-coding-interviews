/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        //level order traversal;
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            int n=q.size();
            while(n){
                Node *curr=q.front();
                q.pop();
                if(n>1){
                    curr->next=q.front();
                }
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                n--;
            }
        }
        return root;
    }
};