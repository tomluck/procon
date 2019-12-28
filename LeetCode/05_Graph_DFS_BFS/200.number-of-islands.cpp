/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
    // not resolved 1st test and other test.
private:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    size_t fHeight = 0;
    size_t fWidth = 0;
    vector<vector<bool>> fSeenVec;

public:
    int
    numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
        {
            return 0;
        }

        // prepare
        fHeight = grid.size();
        fWidth = grid[0].size();
        cout << "fHeight" << fHeight << ", fWidth=" << fWidth << endl;
        int numOfIslands = 0;
        for (size_t i = 0; i != fHeight; ++i) {
            vector<bool> seenWidth;
            for (size_t j = 0; j != fWidth; ++j) {
                seenWidth.push_back(false);
            }
            fSeenVec.push_back(seenWidth);
        }

        // search
        for (size_t i = 0; i != fHeight; ++i) {
            for (size_t j = 0; j != fWidth; ++j)
            {
                fSeenVec[i][j] = true;
                if (grid[i][j] == '0')
                {
                    // cout << "##### SKIP, i=" << i << ", j=" << j << ", grid[i][j]=" << grid[i][j] << endl;
                    continue;
                }
                dfs(i, j, grid);
                cout << "COUNT, i=" << i << ", j=" << j << ", grid[i][j]=" << grid[i][j] << endl;
                ++numOfIslands;
            }
        }
        return numOfIslands;
    }

    void dfs(int x, int y, vector<vector<char>> &grid)
    {
        cout << "dfs, x=" << x << ", y=" << y << ", grid[x][y]=" << grid[x][y] << endl;
        for (size_t dir = 0; dir != 4; ++dir)
        {
            int nextX = x + dx[dir];
            int nextY = y + dy[dir];
            if ((nextX < 0) || (nextX >= fWidth) ||
                (nextY < 0) || (nextY >= fHeight)) {
                continue;
            }
            if (fSeenVec[nextY][nextX] = true)
            {
                continue;
            }
            if (grid[nextX][nextY] == '0') {
                continue;
            }

            dfs(nextX, nextY, grid);
        }
    }
};
// @lc code=end

