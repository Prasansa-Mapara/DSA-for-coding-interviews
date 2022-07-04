/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> sol;
        if(!root) return sol;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            int n=q.size();
            vector<int> tmp;
            while(n--){
                Node *curr=q.front();
                q.pop();
                tmp.push_back(curr->val);
                for(auto i: curr->children){
                    q.push(i);
                }
            }
            sol.push_back(tmp);
        }
        return sol;
    }
};