/* 解法：树形DP
*/
class Solution {
public:
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        dp[root] = { 0, root->val };
        if (root->left) {
            //不偷root节点，递归左子树
            dp[root][0] += rob(root->left);
            //偷root节点，左子树只能不偷
            dp[root][1] += dp[root->left][0];
        }
        //不能乱用else if
        if (root->right) {
            dp[root][0] += rob(root->right);
            dp[root][1] += dp[root->right][0];
        }
        //最后返回根节点偷和不偷的最大值
        return max(dp[root][0], dp[root][1]);
    }
private:
    //树的节点到数组的映射 {0，1}数组第一维数值为不偷此节点，第二维偷此节点
    unordered_map<TreeNode*, vector<int>> dp;
};