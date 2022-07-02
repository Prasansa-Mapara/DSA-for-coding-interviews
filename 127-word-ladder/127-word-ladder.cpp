class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wrd) {
        if(bw==ew){
            return 1;
        }
        
        //this is basically a shortest path i.e. BFS problem;
        unordered_set<string> hash, vis;
        for(auto s: wrd){
            hash.insert(s);
        }
        queue<string> q;
        q.push(bw);
        vis.insert(bw);
        int sol=1;
        
        while(q.size()){
            int n=q.size();
            while(n--){
                string s=q.front();
                q.pop();
                for(int i=0; i<s.size(); i++){
                    char x=s[i];
                    for(char c='a'; c<='z'; c++){
                        s[i]=c;
                        if(hash.find(s)!=hash.end() && vis.find(s)==vis.end()){
                            //if we haven't visited this string and it's present in hash;
                            if(s==ew){
                                return sol+1; //cuz we want number of words in this tranformation;
                            }
                            vis.insert(s);
                            q.push(s);
                        }
                    }
                    s[i]=x;
                }
            }
            sol++;
        }
        
        return 0;
    }
};