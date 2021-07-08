public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        //声明全局变量时前面不能再加描述了
        seq = new ArrayList<String>();
        pre_order(root);
        return String.join(" ", seq);
    }
    //利用先序序列化二叉树
    private void pre_order(TreeNode root){
        if(root == null){
            seq.add("null");
            return ;
        }
        seq.add(Integer.toString(root.val));
        pre_order(root.left);
        pre_order(root.right);
    }
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        seq = Arrays.asList(data.split(" "));
        curr = 0;
        return calcu();
    }

    private TreeNode calcu(){
        if(seq.get(curr).equals("null")){
            curr++;
            return null;
        }
        TreeNode root = new TreeNode(Integer.parseInt(seq.get(curr)));
        curr++;
        root.left = calcu();
        root.right = calcu(); 
        return root;
    }

    private List<String> seq;
    private int curr;
}