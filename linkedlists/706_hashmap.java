package linkedlists;

class ListNode{
    public int key;
    public int val;
    public ListNode next; 
    public ListNode(int key, int val){
        this.key = key;
        this.val = val;
   }
}


class MyHashMap {

    public final int SIZE = (int)1e5;
    public ListNode[] hashmap = new ListNode[SIZE];
    public MyHashMap() {
        for(int i = 0 ; i < SIZE ; i++){
            hashmap[i] = new ListNode(0, 0);
        }
    }
    
    public void put(int key, int value) {
        int hkey = key % SIZE;
        ListNode curr = hashmap[hkey];
        while(curr.next != null){
            if(curr.next.key == key){
                curr.next.val = value;
                return;
            }
            curr = curr.next;
        }
        curr.next = new ListNode(key, value);
    }
    
    public int get(int key) {
        int hkey = key % SIZE;
        ListNode curr = hashmap[hkey].next;
        while(curr != null){
            if(curr.key == key){
                return curr.val;
            }
            curr = curr.next;
        }
        return -1;
    }
    
    public void remove(int key) {
        int hkey = key % SIZE;
        ListNode curr = hashmap[hkey];
        while(curr.next != null){
            if(curr.next.key == key){
                curr.next = curr.next.next;
                return;
            }
            curr = curr.next;
        }
    }
}


/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */