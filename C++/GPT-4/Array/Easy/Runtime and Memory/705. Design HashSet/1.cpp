class MyHashSet {
private:
    vector<bool> keys;
public:
    /** Initialize your data structure here. */
    MyHashSet(): keys(1e6 + 1, false) {
    }
    
    void add(int key) {
        keys[key] = true;
    }
    
    void remove(int key) {
        keys[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return keys[key];
    }
};
