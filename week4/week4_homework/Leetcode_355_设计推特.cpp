/*  建立两个哈希表posts和follows:
    posts  用户id  -> 发布时间, 推文id
    follows 用户id -> 关注列表
*/
class Twitter {
public:
    unordered_map<int, vector<pair<int, int>>> posts;
    unordered_map<int, unordered_set<int>> follows;
    int time = 0;

    Twitter() {

    }

    void postTweet(int userId, int tweetId) {
        posts[userId].push_back(make_pair(time++, tweetId));
    }

    vector<int> getNewsFeed(int userId) {
        vector<pair<int, int>> ps;
        //首先将自己发的推文加入ps
        for (auto selfpost : posts[userId]) ps.push_back(selfpost);
        //然后将已关注者的推文加入
        for (auto follow : follows[userId])
            for (auto post : posts[follow])
                ps.push_back(post);
        //按照时间由大到小排序，时间大的发文最近
        sort(ps.rbegin(), ps.rend());
        //将最新的十条推文加入
        vector<int> res;
        for (int i = 0; i < 10 && i < ps.size(); i++)
            res.push_back(ps[i].second);
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follows[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};