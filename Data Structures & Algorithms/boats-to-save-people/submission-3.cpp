class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int max = *max_element(people.begin(), people.end());

        vector<int> freqMap(max + 1, 0);

        int numBoats{};

        for(int i: people) {
            freqMap[i]++;
        }

        int idx{}, i{1};
        while(idx < people.size()) {
            while(freqMap[i] == 0) {
                ++i;
            }
            people[idx] = i;
            ++idx;
            --freqMap[i];
        }

        int left{};
        int right = people.size() - 1;

        while(left <= right) {
            int remain = limit - people[right];
            --right;
            ++numBoats;
            if (left <= right && remain >= people[left]) {
                ++left;
            }
        }

        return numBoats;
        
    }
};