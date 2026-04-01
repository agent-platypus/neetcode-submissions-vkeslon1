class Solution {
public:
    vector<int> countBits(int n) {
        int power = 1;
        vector<int> res(n+1, 0);
        if(n == 0) {
            return res;
        }
        if (n == 1) {
            return {0,1};
        }
        res[1] = 1;

        for(int i = 2; i < n+1; i++) { 
            int currPow2 = pow(2, power);
            if(i == currPow2) {
                res[i] = 1;
                power++;
            }

            if(i == (currPow2 - 1)) {
                res[i] = power;
            } 

            if (i < currPow2) {
                res[i] = res[i - pow(2, power -1)] + res[pow(2, power - 1)];
            }
        }

        return res;
    }
};
