class LRUCache {
    unordered_map<int, int> m_cache;
    list<int> m_history;
    int m_capacity;
    int m_size;
public:
    LRUCache(int capacity): m_capacity{capacity}, m_size{} {
        
    }
    
    int get(int key) {
        auto it = m_cache.find(key);

        if (it != m_cache.end()) {
            m_history.remove(key);
            m_history.push_back(key);
            return m_cache[key];
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        auto it = m_cache.find(key);

        if (m_size < m_capacity) {
            if (it != m_cache.end()) {
                m_cache[key] = value;

                m_history.remove(key);
                m_history.push_back(key);
            }
            else {
                m_cache[key] = value;
                m_history.push_back(key);
                ++m_size;
            }

        }
        else {
            if (it != m_cache.end()) {
                m_cache[key] = value;
                m_history.remove(key);
                m_history.push_back(key);
            }
            else {
                int LRU_cacheline = m_history.front();
                m_cache.erase(LRU_cacheline);
                m_history.remove(LRU_cacheline);

                m_cache[key] = value;
                m_history.push_back(key);
            }
        }
 
    }
};
