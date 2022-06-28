class Twitter {

   vector<pair<int, int>> whoPosted;
    unordered_map<int, unordered_set<int>> whoFollowWho;
public:
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        whoPosted.push_back({ userId, tweetId });
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> s = whoFollowWho[userId];
        s.insert(userId);
        vector<int> ans;
        for (int i = whoPosted.size() - 1; i > -1 && ans.size() < 10; --i) if (s.find(whoPosted[i].first) != s.end()) ans.push_back(whoPosted[i].second);
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        whoFollowWho[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        whoFollowWho[followerId].erase(followeeId);
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