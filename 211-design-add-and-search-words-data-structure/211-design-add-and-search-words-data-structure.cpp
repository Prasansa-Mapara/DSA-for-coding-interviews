class TrieNode{
    public:
    bool isEnd;
    TrieNode *children[26];
    
    TrieNode(){
        isEnd=false;
        for(int i=0; i<26; i++){
            children[i]=NULL;
        }
    }
};

class WordDictionary {
public:
    TrieNode *root;
    
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
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
    
    bool searchWrd(string &word, TrieNode *curr, int i){
        int n=word.size();
        if(i==n){
            return curr->isEnd;
        }
        if(word[i]!='.'){
            int idx=word[i]-'a';
            if(curr->children[idx]){
                return searchWrd(word, curr->children[idx], i+1);
            }
        }
        else{
           for(int j=0; j<26; j++){
                if(curr->children[j] && searchWrd(word, curr->children[j], i+1)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search(string word) {
        return searchWrd(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */