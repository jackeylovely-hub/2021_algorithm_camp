class Solution {
private:
    TreeNode* dfs(vector<int>& preorder, int l1, int r1, vector<int>& inorder, int l2, int r2) {
        //递归终止条件
        if (l1 > r1) return nullptr;
        //先序第一个数作为根节点
        TreeNode* root = new TreeNode(preorder[l1]);
        //在中序遍历中，找到根节点，并确定左右子树大小
        int mid = l2;
        while (inorder[mid] != root->val) mid++;
        //int leftSize = mid - l2;
        root->left = dfs(preorder, l1 + 1, mid - l2 + l1,
            inorder, l2, mid - 1);
        root->right = dfs(preorder, l1 + mid - l2 + 1, r1,
            inorder, mid + 1, r2);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};