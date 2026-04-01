class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int left = 0;
        int right = matrix.size() - 1;

        int rowwidth = matrix[0].size() - 1;
        // find a row in which the value may reside
        // by checking the first value of the row 
        int mid;
        while(left <= right) {
            mid = (left + right) / 2; 
            if (matrix[mid][0] == target) {
                return true;
            }
            else if (matrix[mid][0] > target) {
                right = mid - 1;
            }
            else { // matrix[mid][0] < target
                left = mid + 1;
            }
        }

        if(mid != 0 && matrix[mid][0] > target && matrix[mid - 1][0] < target) {
            mid--;
        }
        
        left = 0;
        right = matrix[mid].size() - 1; 

        cout << "row = " << mid << ", starting element = " << matrix[mid][0] << endl;
        while(left <= right) {
            int rowmid = (left + right) / 2;
            if (matrix[mid][rowmid] == target) {
                return true;
            }
            else if (matrix[mid][rowmid] > target) {
                right = rowmid - 1;
            } 
            else {
                left = rowmid + 1;
            }
        }

        return false;

    }
};
