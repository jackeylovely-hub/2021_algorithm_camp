
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        //unordered_set<string> blocks;//set的类型
        unordered_set<long long> blocks;
        for (auto& obstacle : obstacles) {
            blocks.insert(calcHash(obstacle[0], obstacle[1]));
        }
        //方向数组的优化：N,E,S,W
        //数组的写法{}
        int dx[4] = { 0,1,0,-1 };
        int dy[4] = { 1,0,-1,0 };
        int x = 0, y = 0;
        int dir = 0;//向北
        int ans = 0;
        for (auto& cmd : commands) {
            if (cmd > 0) {
                for (int i = 0; i < cmd; i++) {
                    int nextx = x + dx[dir];
                    int nexty = y + dy[dir];
                    if (blocks.find(calcHash(nextx, nexty)) != blocks.end()) {
                        break;
                    }
                    //走一步
                    x = nextx;
                    y = nexty;
                    ans = max(ans, x * x + y * y);
                }
            }
            else if (cmd == -1) {
                dir = (dir + 1) % 4;
            }
            else {
                dir = (dir + 3) % 4;
            }
        }
        return ans;
    }

private:
    //string: (-200,300):"-200,300";
    // string calcHash(int x, int y){
    //     return to_string(x) + "," + to_string(y);
    // }
    long long calcHash(int x, int y) {
        return (x + 30000) * 60000LL + y + 30000;
    }
};