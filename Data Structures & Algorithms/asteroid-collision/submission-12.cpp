class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for(int x: asteroids) {
            if ( x > 0 ) {
                res.push_back(x);
            }
            else {
                if (res.empty() || res.back() < 0) {
                    res.push_back(x);
                    continue;
                }

                int currExplosion = res.back() + x;
                if (currExplosion == 0) {
                    res.pop_back();
                    continue;
                }
                else if (currExplosion > 0) {
                    continue;
                }
                int lastAsteroid = 0;
                while( !res.empty() && (res.back() > 0) && (res.back() + x) < 0) {
                    lastAsteroid = res.back();
                    res.pop_back();
                }
                if (!res.empty() && (res.back() + x) == 0 ) {
                    res.pop_back();
                    continue; 
                }
                if (res.empty() || res.back() < 0) {
                    res.push_back(x);
                    continue;
                }

            }
        }
        return res;

    }
};