class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> occurIdx;
        for(int i{}; const auto& x: nums) {
            auto it{occurIdx.find(x)};
            if(it != occurIdx.end()) {
                int distance =  i - it->second ;
                cout<< distance << endl;
                if (distance <= k) {
                    return true;
                } 
            }
            occurIdx[x] = i;
            ++i;
        }

        return false;
    }
};