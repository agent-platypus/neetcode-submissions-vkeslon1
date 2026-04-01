class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> stk;

        for(int i = 0; i < temperatures.size(); i++) {
            int curr_temp = temperatures[i];

            while(!stk.empty() && curr_temp > stk.top().first) {
                auto pair = stk.top();
                stk.pop();
                res[pair.second] = i - pair.second;
            }

            stk.push({curr_temp, i});
        }

        return res;
    }
};
