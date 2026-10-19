#include <print> 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int,int>> tempDay;

        for(int currDay{}; currDay < temperatures.size(); ++currDay) {
            while(!tempDay.empty() && tempDay.top().first < temperatures[currDay]) {
                auto [temp, day] = tempDay.top();
                tempDay.pop();
                res[day] = currDay - day;
            }
            tempDay.push({temperatures[currDay], currDay});
        }

        return res;
    }
};
