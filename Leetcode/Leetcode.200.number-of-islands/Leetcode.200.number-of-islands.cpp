/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (55.08%)
 * Likes:    16572
 * Dislikes: 379
 * Total Accepted:    1.8M
 * Total Submissions: 3.3M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 * 
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<char>> grid_;
    int kRow;
    int kCol;
    void dfs(int row, int col) {
        if (row < 0 || col < 0 || row >= kRow || col >= kCol || grid_.at(row).at(col) == '0') {
            return;
        }
        grid_.at(row).at(col) = '0';
        dfs(row + 1, col);
        dfs(row, col + 1);
        dfs(row - 1, col);
        dfs(row, col - 1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        kRow = grid.size();
        kCol = grid.at(0).size();
        grid_ = grid;
        int count = 0;
        for (int row = 0; row < kRow; row++) {
            for (int col = 0; col < kCol; col++) {
                if (grid_.at(row).at(col) == '1') {
                    dfs(row, col);
                    count++;
                }
            }
        }
        return count;
    }
};
// @lc code=end

