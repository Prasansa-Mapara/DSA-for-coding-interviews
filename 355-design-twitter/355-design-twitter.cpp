#define pii pair<int, int>

class Twitter {
public:
    unordered_map<int, unordered_set<int>> users;
    vector<pii> tweets;
    
    Twitter() {
        
    }
    
    void postTweet(int uid, int tid) {
        tweets.push_back({uid, tid});
    }
    
    vector<int> getNewsFeed(int uid) {
        //we want 10 recent tweets;
        //these tweets should either have been tweeted by the user, or
        //by the users followed by our curr user;
        //which is simple, as our array tweets, is alreayd sorted;
        
        int n=tweets.size();
        vector<int> sol;
        for(int i=n-1; i>=0; i--){ //iterating from the most recent tweet;
             auto curr=tweets[i];
            //if curr user is the given user or given user follows curr user;
            if(uid==curr.first || users[uid].find(curr.first)!=users[uid].end()){
                sol.push_back(curr.second);
                if(sol.size()==10){
                    return sol;
                }
            }
        }
        
        return sol;
    }
    
    void follow(int fid, int feid) {
        users[fid].insert(feid);
    }
    
    void unfollow(int fid, int feid) {
        if(users[fid].find(feid)!=users[fid].end()){
            users[fid].erase(feid);
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