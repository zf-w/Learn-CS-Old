/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (58.90%)
 * Likes:    7864
 * Dislikes: 314
 * Total Accepted:    512.7K
 * Total Submissions: 869.9K
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of structurally unique BST's (binary
 * search trees) which has exactly n nodes of unique values from 1 to n.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: 5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 19
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp_table(n + 1, 0);
        dp_table.at(0) = 1;
        dp_table.at(1) = 1;
        for (int i = 2; i <= n; i++) {
            int head = 0;
            int tail = i - 1;
            int sum = 0;
            while (head < tail) {
                sum += dp_table.at(head) * dp_table.at(tail);
                head++;
                tail--;
            }
            sum *= 2;
            if (head == tail) {
                sum += dp_table.at(head) * dp_table.at(tail);
            }
            dp_table.at(i) = sum;
        }
        return dp_table.at(n);
    }
};
// @lc code=end

