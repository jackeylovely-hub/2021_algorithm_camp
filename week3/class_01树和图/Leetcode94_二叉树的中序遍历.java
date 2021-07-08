class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        seq = new ArrayList<Integer>();
        find(root);
        return seq;
    }
    private void find(TreeNode root){
        if(root == null) return ;
        find(root.left);
        seq.add(root.val);
        find(root.right);
    }
    private List<Integer> seq;
}