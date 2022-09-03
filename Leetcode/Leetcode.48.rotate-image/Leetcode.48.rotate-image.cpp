/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 *
 * https://leetcode.com/problems/rotate-image/description/
 *
 * algorithms
 * Medium (68.18%)
 * Likes:    11086
 * Dislikes: 549
 * Total Accepted:    1M
 * Total Submissions: 1.5M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * You are given an n x n 2D matrix representing an image, rotate the image by
 * 90 degrees (clockwise).
 * 
 * You have to rotate the image in-place, which means you have to modify the
 * input 2D matrix directly. DO NOT allocate another 2D matrix and do the
 * rotation.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
 * Output: [[7,4,1],[8,5,2],[9,6,3]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
 * Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == matrix.length == matrix[i].length
 * 1 <= n <= 20
 * -1000 <= matrix[i][j] <= 1000
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int kRow = matrix.size();
        const int kCol = kRow;
        for (int row = 0; row < kRow; row++) {
            for (int col = row + 1; col < kCol; col++) {
                swap(matrix.at(row).at(col), matrix.at(col).at(row));
            }
        }
        for (int row = 0; row < kRow; row++) {
            int left = 0;
            int right = kRow - 1;
            while (left < right) {
                swap(matrix.at(row).at(left), matrix.at(row).at(right));
                left++;
                right--;
            }
        }
    }
};
// @lc code=end

