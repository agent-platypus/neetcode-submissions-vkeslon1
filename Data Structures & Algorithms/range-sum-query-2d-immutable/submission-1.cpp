class NumMatrix {
    vector<vector<int>> prefixSum;
public:

    NumMatrix(vector<vector<int>>& matrix) {

        int numRows = matrix.size();
        int numCol = matrix[0].size();
        prefixSum = vector<vector<int>>(numRows, vector<int>(numCol,0));

        for(int row{}; row < numRows; ++row) {
            int prefix = matrix[row][0];
            prefixSum[row][0] = prefix;
            for(int col{1}; col < numCol; ++col) {
                prefix += matrix[row][col];
                prefixSum[row][col] = prefix;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int rowSum{};

        for(int row{row1}; row <= row2; ++row) {
            if (!col1) {
                rowSum += prefixSum[row][col2];
            }
            else {
                rowSum += prefixSum[row][col2] - prefixSum[row][col1 - 1];
            }
            
        }

        return rowSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */