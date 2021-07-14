class Solution {
public:
    // 递归函数定义：删除BST中的节点，并且返回新BST的根节点！
    TreeNode* deleteNode(TreeNode* root, int key) {
        //递归终止条件
        if (root == nullptr) return nullptr;
        if (key == root->val) {
            //只有右子树
            if (root->left == nullptr) return root->right;
            //只有左子树
            if (root->right == nullptr) return root->left;
            //找后继
            TreeNode* next = root->right;
            while (next->left != nullptr) next = next->left;
            //先删除val对应节点的后继
            root->right = deleteNode(root->right, next->val);
            //用后继代替被删除的val的节点
            root->val = next->val;
            return root;
        }
        //基于检索实现
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};