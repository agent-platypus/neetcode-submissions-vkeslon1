class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // int stack_buf[10000];

        // std::copy()
        // int hash_code{10000};
        // auto hash_func{ [&, hash_code]() {
        //     for(const auto& x: nums) {

        //     }
        // }};

        unordered_set<int> unique;
        for(const auto& x: nums) {
            if (unique.find(x) != unique.end()) {
                return true;
            }
            unique.insert(x);
        }

        return false;
    }
};