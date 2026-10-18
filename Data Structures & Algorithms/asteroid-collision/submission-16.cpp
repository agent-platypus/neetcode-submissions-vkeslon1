class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        
        for(auto& currAsteroid: asteroids) {
            while(!res.empty() && currAsteroid < 0 && res.back() > 0) {

                int currExplosion = currAsteroid + res.back();
                if (currExplosion == 0) {
                    currAsteroid = 0;
                    res.pop_back();
                }
                else if (currExplosion > 0) {
                    currAsteroid = 0;
                }
                else { // currExplosion < 0
                    res.pop_back();
                }
            }
            if (currAsteroid != 0) {
                res.push_back(currAsteroid);
            }
        }
        

        return res;
    }
};