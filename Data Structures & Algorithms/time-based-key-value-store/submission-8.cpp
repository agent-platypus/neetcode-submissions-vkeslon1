class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>> > storage;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (storage.find(key) == storage.end()) {
            return "";
        }
        
        auto& key_storage = storage[key];

        int left{};
        int right = key_storage.size() - 1;

        int maxPrevTimestamp = -1;
        int indexMaxPrev = -1;

        int mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            int currTimestamp = key_storage[mid].first;
            
            if (currTimestamp <= timestamp) {
                maxPrevTimestamp = max(maxPrevTimestamp, currTimestamp);
                indexMaxPrev = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        // cout << "max prev timestamp = " << maxPrevTimestamp << endl;
        // cout << "mid index = " << mid << endl;
        if (maxPrevTimestamp == -1) { // no timestamps met the condition
            return "";
        }

        return key_storage[indexMaxPrev].second;
        
    }
};
