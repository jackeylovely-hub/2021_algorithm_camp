class Solution {
public:
    // �ݹ麯�����壺ɾ��BST�еĽڵ㣬���ҷ�����BST�ĸ��ڵ㣡
    TreeNode* deleteNode(TreeNode* root, int key) {
        //�ݹ���ֹ����
        if (root == nullptr) return nullptr;
        if (key == root->val) {
            //ֻ��������
            if (root->left == nullptr) return root->right;
            //ֻ��������
            if (root->right == nullptr) return root->left;
            //�Һ��
            TreeNode* next = root->right;
            while (next->left != nullptr) next = next->left;
            //��ɾ��val��Ӧ�ڵ�ĺ��
            root->right = deleteNode(root->right, next->val);
            //�ú�̴��汻ɾ����val�Ľڵ�
            root->val = next->val;
            return root;
        }
        //���ڼ���ʵ��
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};