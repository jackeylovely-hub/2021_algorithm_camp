class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        //�п�
        if (root == nullptr) return {};
        vector<vector<int>> seq;
        queue<pair<Node*, int>>  q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            Node* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            //��ֹ����Խ�磬һ��ʼ��һ����
            if (seq.size() <= depth) seq.push_back({});
            seq[depth].push_back(node->val);
            //��չ����һ��
            for (Node* child : node->children) {
                q.push(make_pair(child, depth + 1));
            }
        }
        return seq;
    }
};