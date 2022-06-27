class Tweet{
    public:
    
    int userId;
    int tweetId;
    int time;
    Tweet(int userId,int tweetId,int time)
    {
        this->userId=userId;
        this->tweetId=tweetId;
        this->time=time;
    }
};

class Twitter {
public:
    
    map<int,set<pair<int,Tweet*>>>userFeed;
    map<int,set<Tweet*>>userPost;
    map<int,set<int>>myFollowers;
    int time;
    
    Twitter() 
    {
        time=1e9;
        userFeed.clear();
        myFollowers.clear();
    }
    
    void postTweet(int userId, int tweetId) 
    {
       Tweet* newTweet = new Tweet(userId,tweetId,time);
       userFeed[userId].insert({time,newTweet});
       userPost[userId].insert(newTweet);
       time--;
        
       for(auto i : myFollowers[userId])
       {
           userFeed[i].insert({newTweet->time,newTweet});
       }
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        vector<int>v;
        for(auto i : userFeed[userId])
        {
            v.push_back(i.second->tweetId);
            if(v.size()==10)
            {
                break;
            }
        }
        
        return v;
    }
    
    void follow(int followerId, int followeeId) 
    {
        myFollowers[followeeId].insert(followerId);
        for(auto it : userPost[followeeId])
        {
            userFeed[followerId].insert({it->time,it});
        }
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        myFollowers[followeeId].erase(followerId);
        for(auto it : userPost[followeeId])
        {
            userFeed[followerId].erase({it->time,it});
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