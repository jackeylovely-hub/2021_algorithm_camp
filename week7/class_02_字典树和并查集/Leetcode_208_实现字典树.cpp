class Trie {
public:
    Trie() { root = new Node(); }
    void insert(string word) { find(word, true, true); }
    bool search(string word) { return find(word, false, true); }
    bool startsWith(string prefix) { return find(prefix, false, false); }

private:
    struct Node {
        int count;
        unordered_map<char, Node*> child;//字符映射
        Node() :count(0) {}
    };

    Node* root;

    bool find(const string& word, bool insert_if_not_exist, bool exact_match) {
        Node* curr = root;
        for (auto& ch : word) {
            if (curr->child.find(ch) == curr->child.end()) {
                if (!insert_if_not_exist) return false;
                curr->child[ch] = new Node();
            }
            curr = curr->child[ch];
        }
        if (insert_if_not_exist) curr->count++;
        return exact_match ? curr->count > 0 : true;
    }
};