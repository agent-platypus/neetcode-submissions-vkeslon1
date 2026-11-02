class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> carSpeedPairs;
        carSpeedPairs.reserve(position.size());

        for(int i{}; i < position.size(); ++i) {
            carSpeedPairs.push_back({position[i], speed[i]});
        }

        sort(carSpeedPairs.begin(), carSpeedPairs.end(), [](pair<int, int> car1, pair<int, int> car2) {
            return car1.first > car2.first;
        });

        // to form a fleet, lets say car 1 is in front of car 2 and then the time it takes to reach
        // the destination for car 2 is less than car1
        // then we form car 1 and car 2 in to 1 fleet and we no longer need to consider car 2's speed
        // since it is restricted to the speed of car 1 and any other car whos position is behind car 2 and their time to destination is less than the leading car in the fleet also joins the fleet
        //
        int numFleets = 1;
        int left{};
        int right{};

        
        auto timeToDest = [target](int carPos, int carSpeed) {
            return static_cast<double>(target - carPos) / static_cast<double>(carSpeed);
        };
        
        double currLeadingCar = timeToDest(carSpeedPairs[left].first, carSpeedPairs[left].second);

        // 7 4 1 0

        // 1 2 2 1

        // 3 3 4.5 10  
        while(right < carSpeedPairs.size()) {
            double currCar = timeToDest(carSpeedPairs[right].first, carSpeedPairs[right].second);

            //cout << "curr car time to dest = " << currCar << endl;
            ++right;
            if (currCar <= currLeadingCar) {
                continue;
            }
            else {
                currLeadingCar = currCar;
                ++numFleets;
            }
        }
        
        return numFleets;
    }
};
