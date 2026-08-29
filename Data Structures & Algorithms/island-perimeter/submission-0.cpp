class Solution {
public:
    int height;
    int width;

    int perimeter = 0;

    pair<int, int> direction[4] = {
        {1, 0}, // right
        {-1, 0}, // left
        {0, 1}, // up
        {0, -1} // down
    };

    int islandPerimeter(vector<vector<int>>& grid) {
        height = grid.size();
        width = grid[0].size();

        

        // search for the first bit of the island, from left to right, top to bottom
        for(int i = 0; i < height; i++) {
            for(int j = 0; j < width; j++) {
                if (grid[i][j]) {
                    dfs(grid, j, i);
                    break;
                }
            }
        }

        return perimeter;


    }

    void dfs(vector<vector<int>>& grid, int x, int y) {
        if (x >= width || y >= height || x < 0 || y < 0 || grid[y][x] == 0 || 
            grid[y][x] == -1) {
            return; 
        }

        grid[y][x] = -1;

        perimeter += numAdjacentBlocks(grid, x, y);

        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }

    // each island piece contributes (4 - num_adjacent_island_blocks) to the perimeter
    int numAdjacentBlocks(vector<vector<int>>& grid, int x, int y) {
        int perimeter_contribution = 4;

        for(int i = 0; i < 4; i++) {
            int dx = x + direction[i].first;
            int dy = y + direction[i].second;

            if (dx < 0 || dx > (width - 1)) {
                continue;
            }
            if (dy < 0 || dy > (height - 1)) {
                continue;
            }

            int adjacent_block = grid[dy][dx];

            if (adjacent_block == 1 || adjacent_block == -1) {
                perimeter--;
            }
        }
        return perimeter_contribution;
    }
};