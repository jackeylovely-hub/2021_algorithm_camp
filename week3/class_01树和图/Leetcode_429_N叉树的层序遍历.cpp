class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        //判空
        if (root == nullptr) return {};
        vector<vector<int>> seq;
        queue<pair<Node*, int>>  q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            Node* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            //防止数组越界，一开始加一个空
            if (seq.size() <= depth) seq.push_back({});
            seq[depth].push_back(node->val);
            //扩展到下一层
            for (Node* child : node->children) {
                q.push(make_pair(child, depth + 1));
            }
        }
        return seq;
    }
};