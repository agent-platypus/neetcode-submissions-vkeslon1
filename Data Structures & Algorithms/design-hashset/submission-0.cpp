class MyHashSet {

private:
    static const int size = 10000;
    list<int> table[size];

    int hashFunc(int key) {
        return key % size;
    }
    
public:

    MyHashSet() {
        
    }
    
    void add(int key) {
        int index = hashFunc(key);

        for(auto val: table[index]) {
            if (val == key) {
                return;
            }
        }
        table[index].push_back(key);
    }
    
    void remove(int key) {
        int index = hashFunc(key);
        table[index].remove(key);
        // for(auto val: table[index]) {
        //     auto it = table[index].find(val);
        //     if (it != table[index].end()) {
        //         table[index].erase(it);
        //     }
        // }

    }
    
    bool contains(int key) {
        int index = hashFunc(key);

        auto it = find(table[index].begin(), table[index].end(), key);

        if (it != table[index].end()) {
            return true;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */