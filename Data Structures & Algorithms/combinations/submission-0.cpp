class Solution {
public:
    int maxNum;
    int maxSize;
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        maxNum = n;
        maxSize = k;
        dfs(1, res, curr);
        return res;
    }

    void dfs(int index, vector<vector<int>>& res, vector<int>& curr) {
        if (curr.size() == maxSize) {
            res.push_back(curr);
            return;
        }

        if (index > maxNum) {
            return;
        }

        curr.push_back(index);
        dfs(index + 1, res, curr);
        curr.pop_back();
        dfs(index + 1, res, curr);
    }
};