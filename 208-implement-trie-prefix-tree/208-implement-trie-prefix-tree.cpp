class TrieNode{
    public: 
    bool isEnd; 
    TrieNode* children[26];
    
    TrieNode(){ //default constructor;
        isEnd=false;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
    }
};

class Trie {
public:
    TrieNode *root; //this will pt to the root node;
    
    Trie() {
        root=new TrieNode(); //initialize the root node;
    }
    
    void insert(string word) {
        TrieNode *curr=root;
        int n=word.size();
        for(int i=0; i<n; i++){
            int idx=word[i]-'a';
            if(!curr->children[idx]){
                curr->children[idx]=new TrieNode();
            }
            curr=curr->children[idx];
        }
        curr->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode *curr=root;
        int n=word.size();
        for(int i=0; i<n; i++){
            int idx=word[i]-'a';
            if(!curr->children[idx]){
                return false;
            }
            curr=curr->children[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr=root;
        int n=prefix.size();
        for(int i=0; i<n; i++){
            int idx=prefix[i]-'a';
            if(!curr->children[idx]){
                return false;
            }
            curr=curr->children[idx];
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