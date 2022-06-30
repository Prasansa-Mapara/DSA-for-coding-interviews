#define pii pair<int, int>

class Twitter {
public:
    unordered_map<int, unordered_set<int>> hash;
    vector<pii> v;
    
    Twitter() {
        
    }
    
    void postTweet(int uid, int tid) {
        v.push_back({uid, tid});
    }
    
    vector<int> getNewsFeed(int uid) {
        //the most recent tweet's in the end;
        int n=v.size();
        vector<int> sol;
        for(int i=n-1; i>=0; i--){
            int curUser=v[i].first, curTweet=v[i].second;
            //curUser either has to be same as the given user,
            //or it should be one of the users followed by the given user;
            if(curUser==uid || hash[uid].find(curUser)!=hash[uid].end()){
                sol.push_back(curTweet);
                if(sol.size()==10){
                    return sol;
                }
            }
        }
        //if num of tweets are less than 10;
        return sol;
    }
    
    void follow(int fr, int fe) {
        hash[fr].insert(fe);
    }
    
    void unfollow(int fr, int fe) {
        if(hash[fr].find(fe)!=hash[fr].end()){
            hash[fr].erase(fe);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */