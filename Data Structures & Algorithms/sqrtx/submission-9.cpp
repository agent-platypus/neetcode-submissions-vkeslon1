class Solution {
public:
    int mySqrt(int x) {
        
       long long res = x;

       while(res * res > x) {
        res = (res + x/res) >> 1;
       }

        return res;


    }
};