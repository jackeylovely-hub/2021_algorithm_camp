/*
* ����Ҫ��������Ϣ���㣬�ȵݹ����
* ����Ҫ���ڵ����Ϣ���㣬�ȴ����ݹ�
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        //�������ҽڵ�
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};