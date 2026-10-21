class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());

        int left{};
        int right = people.size() - 1;

        int numBoats{};
        while(left <= right) {
            int remain = limit - people[right];
            ++numBoats;
            --right;
            if ( left <= right && remain >= people[left]) {
                ++left;
            }
            
        }

        return numBoats;
    }
};