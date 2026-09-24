class MyHashMap {
public:
    MyHashMap()  {
        
    }
    
    void put(int key, int value) {
        int bucket = hashFunction(key);

        auto& curr_bucket = hashMap[bucket];
        auto it = curr_bucket.begin();

        if (it == curr_bucket.end()) {
            curr_bucket.push_back({key, value});
            return;
        }

        for(; it != curr_bucket.end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }

        curr_bucket.push_back({key,value});
        // how to create a key,value pair at the position of the current iterator? 

    }
    
    int get(int key) {
        int bucket = hashFunction(key);

        auto& curr_bucket = hashMap[bucket];
        auto it = curr_bucket.begin();

        for(; it != curr_bucket.end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }

        if (it == curr_bucket.end()) {
            return -1;
        }
    }
    
    void remove(int key) {
        int bucket = hashFunction(key);

        auto& curr_bucket = hashMap[bucket];
        auto it = curr_bucket.begin();

        curr_bucket.remove_if([key](auto it) {
            return it.first == key;
        });
       
    }

    int hashFunction(int key) {
        return key % numBuckets;
    }
private:
    static const int numBuckets = 10;
    list<pair<int,int>> hashMap[numBuckets];
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */