class LRUCache {
public:
    unordered_map<int, int> cache;
    list<int> LRU_list; 
    uint32_t size;
    uint32_t LRU_capacity;

    LRUCache(int capacity) {
        cache.reserve(capacity);
        LRU_capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            resetkey_LRU(key);
            return cache[key];
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {

        if (size < LRU_capacity) {
            
            if (cache.find(key) == cache.end()) {
                LRU_list.push_back(key);
                size++;
            }
            else {
                resetkey_LRU(key);
            }
            cache[key] = value;
        
        }

        else {
            if (cache.find(key) != cache.end()) { //replace the existing key with the new value
                resetkey_LRU(key);
                cache[key] = value;
            }
            else { //need to replace the least recently used element 
                int LRU_key = LRU_list.front();
                // verify that the least used key exists in the list

                // while( cache.find(LRU_key) == cache.end() ) {
                LRU_list.pop_front();
                //     LRU_key = LRU_list.front();
                // }

                cache.erase(LRU_key);
                cache[key] = value;
                LRU_list.push_back(key);
            }


        }
    }

    void resetkey_LRU(int key) {
        LRU_list.remove(key);
        LRU_list.push_back(key);
    }
};
