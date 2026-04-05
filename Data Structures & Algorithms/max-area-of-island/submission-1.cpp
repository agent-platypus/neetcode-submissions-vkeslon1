class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxarea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int currIslandArea = dfs(grid, i, j);
                    maxarea = max(maxarea, currIslandArea);
                }
            }
        }

        return maxarea;
    }

        int dfs(vector<vector<int>>& grid, int row, int col) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
            grid[row][col] == -1 || grid[row][col] == 0) {
                return 0;
        }

        grid[row][col] = -1;
        return 1 + dfs(grid, row + 1, col) + dfs(grid, row, col + 1) + dfs(grid, row - 1, col) + dfs(grid, row, col - 1);

    }
};
