
/* 解法一：未优化版
    直接遍历所有的string然后从字典树中查询时间复杂度过大，
    需要两个指针同时遍历字典树和图；
*/
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& _board, vector<string>& words) {
        board = _board;
        m = board.size();
        n = board[0].size();
        //建立字典树
        root = new Node();
        for (auto& word : words)  insert(word);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited = vector<vector<bool>>(m, vector<bool>(n, false));
                visited[i][j] = true;
                //str+当前的字符，调试错误
                dfs(i, j, root, str + board[i][j]);
            }
        }
        return res;
    }
private:
    struct Node {
        int count;
        unordered_map<char, Node*> child;
        Node() :count(0) {}
    };
    void dfs(int x, int y, Node* curr, string str) {
        if (curr->child.find(board[x][y]) == curr->child.end()) return;
        curr = curr->child[board[x][y]];
        if (curr->count > 0) {
            res.push_back(str);
            //需要判重
            curr->count = 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            dfs(nx, ny, curr, str + board[nx][ny]);
            visited[nx][ny] = false;
        }
    }

    void insert(string& word) {
        Node* curr = root;
        for (auto& ch : word) {
            //注意这里是为空的时候插入，很容易写成 != 
            if (curr->child.find(ch) == curr->child.end()) {
                curr->child[ch] = new Node();
            }
            curr = curr->child[ch];
        }
        curr->count++;
    }

    vector<vector<char>> board;
    vector<vector<bool>> visited;
    vector<string> res;
    //上 右 下 左
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };
    string str;
    Node* root;
    int m;
    int n;
};
//解法二：优化版  直接在字典树中存储string
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& _board, vector<string>& words) {
        board = _board;
        m = board.size();
        n = board[0].size();
        //建立字典树
        root = new Node();
        for (auto& word : words)  insert(word);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited = vector<vector<bool>>(m, vector<bool>(n, false));
                visited[i][j] = true;
                dfs(i, j, root);
            }
        }
        return res;
    }
private:
    struct Node {
        string* word;
        unordered_map<char, Node*> child;
    };
    void dfs(int x, int y, Node* curr) {
        if (curr->child.find(board[x][y]) == curr->child.end()) return;
        curr = curr->child[board[x][y]];
        if (curr->word != nullptr) {
            res.push_back(*curr->word);
            //需要判重
            curr->word = nullptr;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            dfs(nx, ny, curr);
            visited[nx][ny] = false;
        }
    }
    void insert(string& word) {
        Node* curr = root;
        for (auto& ch : word) {
            //注意这里是为空的时候插入，很容易写成 != 
            if (curr->child[ch] == nullptr) {
                curr->child[ch] = new Node();
            }
            curr = curr->child[ch];
        }
        curr->word = &word;
    }

    vector<vector<char>> board;
    vector<vector<bool>> visited;
    vector<string> res;
    //上 右 下 左
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };
    string str;
    Node* root;
    int m;
    int n;
};
//解法三：优化 aaaaaa情况
/*
    直接遍历所有的string然后从字典树中查询时间复杂度过大，
    需要两个指针同时遍历字典树和图；
*/
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& _board, vector<string>& words) {
        board = _board;
        m = board.size();
        n = board[0].size();
        //建立字典树
        root = new Node();
        for (auto& word : words)  insert(word);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                visited = vector<vector<bool>>(m, vector<bool>(n, false));
                visited[i][j] = true;
                dfs(i, j, root);
            }
        }
        return res;
    }
private:
    struct Node {
        string* word;    // 实际单词的引用
        unordered_map<char, Node*> child;
    };
    void dfs(int x, int y, Node* curr) {
        if (curr->child.find(board[x][y]) == curr->child.end()) return;
        Node* fa = curr;
        curr = fa->child[board[x][y]];
        if (curr->word != nullptr) {
            res.push_back(*curr->word);
            //需要判重
            curr->word = nullptr;
        }
        if (curr->child.empty()) {
            fa->child.erase(board[x][y]);
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (visited[nx][ny]) continue;
            visited[nx][ny] = true;
            dfs(nx, ny, curr);
            visited[nx][ny] = false;
        }
    }

    void insert(string& word) {
        Node* curr = root;
        for (auto& ch : word) {
            //注意这里是为空的时候插入，很容易写成 != 
            if (curr->child[ch] == nullptr) {
                curr->child[ch] = new Node();
            }
            curr = curr->child[ch];
        }
        curr->word = &word;
    }

    vector<vector<char>> board;
    vector<vector<bool>> visited;
    vector<string> res;
    //上 右 下 左
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { 1,0,-1,0 };
    Node* root;
    int m;
    int n;
};