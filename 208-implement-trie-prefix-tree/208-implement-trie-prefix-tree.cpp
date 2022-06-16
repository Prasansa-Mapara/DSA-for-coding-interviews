class TrieNode{
    public:
    
    bool isEnd; //marking the end of a word;
    TrieNode* children[26]; //26 children nodes;
    
    TrieNode(){
        isEnd=false;
        for(int i=0; i<26; i++){
            children[i]=NULL; //initially all nodes are null;
        }
    }
};

class Trie {
    TrieNode *root; //when we declare a root node, it will automatically have 26 null children, and it wont be the end of a sentence;
public:
    Trie() {
        root=new TrieNode;
    }
    
    void insert(string word) {
        int n=word.size();
        TrieNode *curr=root;
        for(int i=0; i<n; i++){
            int idx=word[i]-'a'; //lowercase chars;
            if(!curr->children[idx]){ //if its a null node then we need to insert; 
                curr->children[idx]=new TrieNode();
            }
            curr=curr->children[idx];
        }
        curr->isEnd=true; //marks the end of the word;
    }
    
    bool search(string word) {
        int n=word.size();
        TrieNode *curr=root;
        for(int i=0; i<n; i++){
            int idx=word[i]-'a';
            if(curr->children[idx]){
                curr=curr->children[idx];
            }
            else{
                return false;
            }
        }
        if(curr->isEnd){
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        TrieNode *curr=root;
        for(int i=0; i<n; i++){
            int idx=prefix[i]-'a';
            if(curr->children[idx]){
                curr=curr->children[idx];
            }
            else{
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */