class MyHashSet {
public:
    MyHashSet() {
        hashset.fill(-1);
    }
    
    void add(int key) {
        int idx{genHashKey(key)};

        hashset.at(idx) = key;
    }
    
    void remove(int key) {
        if (contains(key)) {
            hashset.at(genHashKey(key)) = -1;
        }
    }
    
    bool contains(int key) {
        int idx{genHashKey(key)};
        return (hashset.at(idx) != -1);
    }
private:
    // vector<int> hashset;
    int genHashKey(int key) {
        return key % hash_func;
    }
    static const int hash_func{1000000};
    array<int, 1000000> hashset{};
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */