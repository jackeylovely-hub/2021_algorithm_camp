/*  ����������ϣ��posts��follows:
    posts  �û�id  -> ����ʱ��, ����id
    follows �û�id -> ��ע�б�
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
        //���Ƚ��Լ��������ļ���ps
        for (auto selfpost : posts[userId]) ps.push_back(selfpost);
        //Ȼ���ѹ�ע�ߵ����ļ���
        for (auto follow : follows[userId])
            for (auto post : posts[follow])
                ps.push_back(post);
        //����ʱ���ɴ�С����ʱ���ķ������
        sort(ps.rbegin(), ps.rend());
        //�����µ�ʮ�����ļ���
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