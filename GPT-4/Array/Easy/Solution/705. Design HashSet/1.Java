class MyHashSet {
    boolean[] arr = new boolean[1000001]; // since the range of the key is from 0 to 10^6

    public MyHashSet() {
        
    }
    
    public void add(int key) {
        arr[key] = true;
    }
    
    public void remove(int key) {
        arr[key] = false;
    }
    
    public boolean contains(int key) {
        return arr[key];
    }
}
