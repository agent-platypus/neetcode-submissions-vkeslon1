class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, j, i);
                    numIslands++;
                }
            }
        }
        return numIslands;

    }
    
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if(x < 0 || y < 0 || x >= grid[0].size() || y >= grid.size() ||
            grid[y][x] == '0' || grid[y][x] == 'X') {
            return;
        }
        grid[y][x] = 'X';
        dfs(grid, x + 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x - 1, y);
        dfs(grid, x, y - 1);
    }
};
