//解法一：Cpp递归版本
class Solution {
public:
    vector<int> preorder(Node* root) {
        find(root);
        return seq;
    }

    void find(Node* root) {
        if (root == nullptr) return;
        seq.push_back(root->val);
        for (Node* child : root->children) {
            find(child);
        }
    }
private:
    vector<int> seq;
};
//解法二：Java迭代版本
class Solution {
    public List<Integer> preorder(Node root) {
        List<Integer> seq = new ArrayList<Integer>();
        Stack<Node> s = new Stack<Node>();
        s.push(root);
        while (!s.isEmpty()) {
            Node node = s.pop();
            if (node == null) break;
            seq.add(node.val);
            for (int i = node.children.size() - 1; i >= 0; i--) {
                s.push(node.children.get(i));
            }
        }
        return seq;
    }
}