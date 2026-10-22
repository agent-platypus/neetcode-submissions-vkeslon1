class Solution {
public:
    int mySqrt(int x) {
        
        long long left{1};
        long long right{x};


        long long sqrt;
        while(left <= right) {
            sqrt = left + ((right - left) >> 1);
            long long square = sqrt * sqrt;
            if (square == x) {
                return sqrt;
            }
            else if (square > x) {
                right = sqrt - 1;
            }
            else {
                left = sqrt + 1;
            }

        }

        return right;
    }
};


//1 2 3 4 5 6 7 8 9 10 11 12 13 

//