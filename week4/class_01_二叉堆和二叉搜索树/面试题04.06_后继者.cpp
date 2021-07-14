/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//为了便于理解可将root替换为curr
class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        return find(root, p.val);
    }
    //找到val(val可能不存在)
    private TreeNode find(TreeNode root, int val) {
        TreeNode ans = null;
        while (root != null) {
            //case 1:如果不存在右子树，找到经过的路径中最小的节点
            if (val < root.val) {
                if (ans == null || ans.val > root.val) {
                    ans = root;
                }
            }
            //case 2:如果存在右子树，找到右子树最左的节点
            if (val == root.val) {
                if (root.right != null) {
                    root = root.right;
                    while (root.left != null) root = root.left;
                    return root;
                }
                break;
            }
            //基于检索
            if (val < root.val) root = root.left;
            else               root = root.right;
        }
        return ans;
    }
}