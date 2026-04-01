class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int best = 0;

        for (int x : s) {
            // only start counting at the beginning of a run
            if (!s.count(x - 1)) {
                int len = 1;
                int y = x;
                while (s.count(y + 1)) {
                    y++;
                    len++;
                }
                best = max(best, len);
            }
        }
        return best;
    }
};
