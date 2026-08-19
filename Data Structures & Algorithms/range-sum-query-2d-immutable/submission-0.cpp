class NumMatrix {
private:
    vector<vector<int>> prefix;
    vector<vector<int>> postfix;

    vector<int> row_sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int num_rows = matrix.size();
        int num_col = matrix[0].size();

        prefix = vector<vector<int>>(num_rows, vector<int>(num_col, 0));
        postfix = vector<vector<int>>(num_rows, vector<int>(num_col, 0));

        cout << "rows" << num_rows;
        cout << endl << "columns = " << num_col;
        for(int i = 0; i < num_rows; i++) {
            int j;
            vector<int> pre;
            vector<int> post;
            for(j = 0; j < num_col; j++) {
                if(j == 0) {
                    prefix[i][j] = matrix[i][j];
                    postfix[i][(num_col - 1)] = matrix[i][(num_col - 1)];
                } 
                else {
                    prefix[i][j] = matrix[i][j] + prefix[i][j-1];
                    postfix[i][(num_col - 1) - j] = matrix[i][(num_col - 1) - j] + postfix[i][(num_col - 1) - j + 1];
                }
            }
            row_sum.push_back(prefix[i][j-1]);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++) {
            int curr_sum = (row_sum[i] - prefix[i][col2]) + (row_sum[i] - postfix[i][col1]); 
            sum += (row_sum[i] - curr_sum);
        }

        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */