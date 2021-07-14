/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
//Ϊ�˱������ɽ�root�滻Ϊcurr
class Solution {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        return find(root, p.val);
    }
    //�ҵ�val(val���ܲ�����)
    private TreeNode find(TreeNode root, int val) {
        TreeNode ans = null;
        while (root != null) {
            //case 1:������������������ҵ�������·������С�Ľڵ�
            if (val < root.val) {
                if (ans == null || ans.val > root.val) {
                    ans = root;
                }
            }
            //case 2:����������������ҵ�����������Ľڵ�
            if (val == root.val) {
                if (root.right != null) {
                    root = root.right;
                    while (root.left != null) root = root.left;
                    return root;
                }
                break;
            }
            //���ڼ���
            if (val < root.val) root = root.left;
            else               root = root.right;
        }
        return ans;
    }
}