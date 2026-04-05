class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int maxarea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int currIslandArea = 0;
                    dfs(grid, i, j, currIslandArea);
                    cout << currIslandArea; 
                    maxarea = max(maxarea, currIslandArea);
                }
            }
        }

        return maxarea;
    }

    void dfs(vector<vector<int>>& grid, int row, int col, int& islandArea) {
        if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
            grid[row][col] == -1 || grid[row][col] == 0) {
                return;
        }

        grid[row][col] = -1;
        islandArea++;
        dfs(grid, row + 1, col, islandArea);
        dfs(grid, row, col + 1, islandArea);
        dfs(grid, row - 1, col, islandArea);
        dfs(grid, row, col - 1, islandArea);

        
    }
};
