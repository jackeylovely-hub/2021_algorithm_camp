
class LRUCache {
    private class Node {
        Node pre;
        Node next;
        int  key;
        int  value;
    }
    private HashMap<Integer, Node>  map;
    private Node head;
    private Node tail;
    private int capacity;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<Integer, Node>();
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.pre = head;
    }

    public int get(int key) {
        if (!map.containsKey(key)) return -1;
        Node node = map.get(key);
        //从链表中删除
        this.removeFromList(node);
        //加入链表头部
        this.insertToListHead(node.key, node.value);
        return node.value;
    }

    public void put(int key, int value) {
        if (map.containsKey(key)) {
            Node node = map.get(key);
            this.removeFromList(node);
            this.insertToListHead(key, value);
        }
        else {
            Node node = this.insertToListHead(key, value);
            this.map.put(key, node);
        }
        if (this.map.size() > this.capacity) {
            this.removeFromList(tail.pre);
        }
    }

    private void removeFromList(Node node) {
        node.pre.next = node.next;
        node.next.pre = node.pre;
        this.map.remove(node.key);
    }

    private Node insertToListHead(int key, int value) {
        Node node = new Node();
        node.key = key;
        node.value = value;
        //与head前一个节点建立联系
        node.next = head.next;
        head.next.pre = node;
        //与head建立联系
        node.pre = head;
        head.next = node;
        this.map.put(key, node);
        return node;
    }
}
