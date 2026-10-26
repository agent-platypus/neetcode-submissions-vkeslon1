class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // search space is the input matrix
        // apply binary search on the whole range of input
        // flatten the array into 1D

        int numRow = matrix.size();
        int numCol = matrix[0].size();
        int numElem = numRow * numCol;


        // 8  -> row 2, col 0

        // i * row + col = 8

        // 8 / (num col) -> row

        // 8 % col -> col 

        // 8 / 3 -> 2 

        // 8 % 3 -> 2

        auto conv1DCoord = [&](int coord) {

            int row{coord / numCol};
            int col{coord % numCol};
            return matrix[row][col];
        };
        int left{};
        int right{numElem - 1};


        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            int midElem{conv1DCoord(mid)};
            if (midElem == target) {
                return true;
            }
            else if (midElem > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return false;
    }


};
