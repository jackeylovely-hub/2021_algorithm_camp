class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        father = new HashMap<Integer,TreeNode>();
        calcfather(root);
        redNodes = new HashSet<Integer>();
        redNodes.add(root.val);
        //首先将p走过的节点标红，一直标记到root
        while(p.val != root.val){
            redNodes.add(p.val);
            p = father.get(p.val);
        }
        //其次，看标红的路径中是否有q,没有的话，继续往上找父节点
        while(!redNodes.contains(q.val)){
            q = father.get(q.val);
        }
        return q;
    }
    //存储父节点
    private void calcfather(TreeNode root){
        if(root == null) return;
        if(root.left != null){
            father.put(root.left.val,root);
            calcfather(root.left);
        }
        if(root.right != null){
            father.put(root.right.val,root);
            calcfather(root.right);
        }
    }
    private Map<Integer,TreeNode> father;
    private Set<Integer> redNodes;
}