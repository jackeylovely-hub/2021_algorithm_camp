/*
* 若需要子树的信息计算，先递归后处理
* 若需要父节点的信息计算，先处理后递归
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        //交换左右节点
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};