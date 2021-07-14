class Solution {
    //往树中插入节点，并且返回根：root存在返回原来的root,不存在返回新建节点
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }
        if (root.val == val) {
            return root;
        }
        if (root.val < val) {
            root.right = insertIntoBST(root.right, val);
        }
        if (root.val > val) {
            root.left = insertIntoBST(root.left, val);
        }
        return root;
    }
}