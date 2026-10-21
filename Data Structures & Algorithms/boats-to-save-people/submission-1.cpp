class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());

        int left{};
        int right = people.size() - 1;

        int numBoats{};
        while(left <= right) {

            if (right == left) {
                ++numBoats;
                break;
            }
            if (people[right] == limit) {
                ++numBoats;
                --right;
                continue;
            }

            if (people[left] == limit) {
                ++numBoats;
                ++left;
                continue;
            }
            // 1 2 4 5

            // 1 2 2 3 3  limit = 3

            // 3 3 4 5  numBoat = 1
            // 3 3 4 5  
            if (people[right] + people[left] <= limit) {
                ++numBoats;
                --right;
                ++left;
            }

            else { // people[right] + people[left]  > limit 
                ++numBoats;
                --right;
            }
        }

        return numBoats;
    }
};