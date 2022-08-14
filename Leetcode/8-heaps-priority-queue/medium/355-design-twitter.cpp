/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Tweet {
public:
    int id;
    int time;
    Tweet(int id, int time) {
        this->id = id;
        this->time = time;
    }
};

class User {
public:
    int id;
    unordered_set<int> followers;
    unordered_set<int> following;
    vector<Tweet> tweets;
    User(int userId) {
        this->id = userId;
    }
};

class HeapElement {
public:
    int time;
    int tweetId;
    int followeeId;
    int nextIndex;
    HeapElement(int time, int tweetId, int followeeId, int nextIndex) {
        this->time = time;
        this->tweetId = tweetId;
        this->followeeId = followeeId;
        this->nextIndex = nextIndex;
    }
};

class MaxHeapCompare {
    public:
    bool operator()(HeapElement h1, HeapElement h2) {
        return h1.time < h2.time;
    }
};

class Twitter {
public:

    int time;
    unordered_map<int, User*> users; 

    Twitter() {
        this->time = 0;
    }
    
    void postTweet(int userId, int tweetId) {

        // add a new user if the user with userId
        // does not exist yet
        if(users.find(userId) == users.end()) {
            users[userId] = new User(userId); 
        } 
        
        // add the new tweet to user's tweets array
        Tweet tweet(tweetId, time);
        users[userId]->tweets.push_back(tweet);
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {

        // if we did not find the user
        if(users.find(userId) == users.end()) return {};

        // max heap, keeps tweets sorted according 
        // to the time at which they were posted
        priority_queue<HeapElement, vector<HeapElement>, MaxHeapCompare> maxHeap;
        int heapSize = 10;

        unordered_set<int> following = users[userId]->following;
        following.insert(userId); // including userId to local following list as well since we also need to retreive his posts

        for(int followeeId : following) {
            vector<Tweet> followeeTweets = users[followeeId]->tweets;

            int n = followeeTweets.size();
            if(n == 0) continue; // no tweets by this user

            int index = n - 1;
            Tweet lastTweet = followeeTweets[index];
            maxHeap.push(HeapElement(lastTweet.time, lastTweet.id, followeeId, index - 1));
        }

        // getting all the top 10 (or < 10) tweets
        // that will occur in the news feed
        vector<int> allTweets;
        while(allTweets.size() < heapSize && !maxHeap.empty()) {
            HeapElement curr = maxHeap.top();
            allTweets.push_back(curr.tweetId);
            maxHeap.pop();

            if(curr.nextIndex >= 0) {
                Tweet nextTweet = users[curr.followeeId]->tweets[curr.nextIndex];
                maxHeap.push(HeapElement(nextTweet.time, nextTweet.id, curr.followeeId, curr.nextIndex - 1));
            }
        }

        return allTweets;
    }
    
    void follow(int followerId, int followeeId) {

        // follower doesn't exist yet
        // create a new user with id = followerId
        if(users.find(followerId) == users.end()) {
            users[followerId] = new User(followerId);
        }

        // followee doesn't exist yet
        // create a new user with id = followeeId
        if(users.find(followeeId) == users.end()) {
            users[followeeId] = new User(followeeId);
        }

        // establish the connection
        users[followeeId]->followers.insert(followerId);
        users[followerId]->following.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        
        // if either of them don't exist yet, return
        if(users.find(followerId) == users.end()) return;
        if(users.find(followeeId) == users.end()) return;

        // follower unfollows followee
        users[followeeId]->followers.erase(followerId);
        users[followerId]->following.erase(followeeId);
    }
};

// class Tweet {
// public:
//     int id;
//     int time;
//     Tweet(int id, int time) {
//         this->id = id;
//         this->time = time;
//     }
// };

// class User {
// public:
//     int id;
//     unordered_set<int> followers;
//     unordered_set<int> following;
//     vector<Tweet> tweets;
//     User(int userId) {
//         this->id = userId;
//     }
// };

// class MaxHeapCompare {
//     public:
//     bool operator()(Tweet t1, Tweet t2) {
//         return t1.time < t2.time;
//     }
// };

// class Twitter {
// public:

//     int time;
//     unordered_map<int, User*> users; 

//     Twitter() {
//         this->time = 0;
//     }
    
//     void postTweet(int userId, int tweetId) {

//         // add a new user if the user with userId
//         // does not exist yet
//         if(users.find(userId) == users.end()) {
//             users[userId] = new User(userId); 
//         } 
        
//         // add the new tweet to user's tweets array
//         Tweet tweet(tweetId, time);
//         users[userId]->tweets.push_back(tweet);
//         time++;
//     }
    
//     vector<int> getNewsFeed(int userId) {

//         // if we did not find the user
//         if(users.find(userId) == users.end()) return {};

//         // max heap, keeps tweets sorted according 
//         // to the time at which they were posted
//         priority_queue<Tweet, vector<Tweet>, MaxHeapCompare> maxHeap;
//         int heapSize = 10;

//         unordered_set<int> following = users[userId]->following;
//         following.insert(userId); // including userId to local following list as well since we also need to retreive his posts

//         for(int followeeId : following) {
//             vector<Tweet> followeeTweets = users[followeeId]->tweets;

//             // if user has posted less than 10 tweets,
//             // include all of them in the max heap
//             if(followeeTweets.size() <= heapSize) {
//                 for(Tweet tweet : followeeTweets) {
//                     maxHeap.push(tweet);
//                 } 
//             } 
            
//             // only including top 10 tweets of every user
//             // into the max heap for efficiency
//             else {
//                 int i = followeeTweets.size() - 1;
//                 int n = heapSize;
//                 while(n != 0) {
//                     maxHeap.push(followeeTweets[i]);
//                     n--;
//                     i--;
//                 }
//             }
//         }

//         // getting all the top 10 (or < 10) tweets
//         // that will occur in the news feed
//         vector<int> allTweets;
//         while(heapSize != 0 && !maxHeap.empty()) {
//             allTweets.push_back(maxHeap.top().id);
//             maxHeap.pop();
//             heapSize--;
//         }

//         return allTweets;
//     }
    
//     void follow(int followerId, int followeeId) {

//         // follower doesn't exist yet
//         // create a new user with id = followerId
//         if(users.find(followerId) == users.end()) {
//             users[followerId] = new User(followerId);
//         }

//         // followee doesn't exist yet
//         // create a new user with id = followeeId
//         if(users.find(followeeId) == users.end()) {
//             users[followeeId] = new User(followeeId);
//         }

//         // establish the connection
//         users[followeeId]->followers.insert(followerId);
//         users[followerId]->following.insert(followeeId);
//     }
    
//     void unfollow(int followerId, int followeeId) {
        
//         // if either of them don't exist yet, return
//         if(users.find(followerId) == users.end()) return;
//         if(users.find(followeeId) == users.end()) return;

//         // follower unfollows followee
//         users[followeeId]->followers.erase(followerId);
//         users[followerId]->following.erase(followeeId);
//     }
// };
