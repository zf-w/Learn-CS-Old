/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 *
 * https://leetcode.com/problems/gas-station/description/
 *
 * algorithms
 * Medium (44.78%)
 * Likes:    8742
 * Dislikes: 753
 * Total Accepted:    526.4K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,4,5]\n[3,4,5,1,2]'
 *
 * There are n gas stations along a circular route, where the amount of gas at
 * the i^th station is gas[i].
 * 
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to
 * travel from the i^th station to its next (i + 1)^th station. You begin the
 * journey with an empty tank at one of the gas stations.
 * 
 * Given two integer arrays gas and cost, return the starting gas station's
 * index if you can travel around the circuit once in the clockwise direction,
 * otherwise return -1. If there exists a solution, it is guaranteed to be
 * unique
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
 * Output: 3
 * Explanation:
 * Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 +
 * 4 = 4
 * Travel to station 4. Your tank = 4 - 1 + 5 = 8
 * Travel to station 0. Your tank = 8 - 2 + 1 = 7
 * Travel to station 1. Your tank = 7 - 3 + 2 = 6
 * Travel to station 2. Your tank = 6 - 4 + 3 = 5
 * Travel to station 3. The cost is 5. Your gas is just enough to travel back
 * to station 3.
 * Therefore, return 3 as the starting index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: gas = [2,3,4], cost = [3,4,3]
 * Output: -1
 * Explanation:
 * You can't start at station 0 or 1, as there is not enough gas to travel to
 * the next station.
 * Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 =
 * 4
 * Travel to station 0. Your tank = 4 - 3 + 2 = 3
 * Travel to station 1. Your tank = 3 - 3 + 3 = 3
 * You cannot travel back to station 2, as it requires 4 unit of gas but you
 * only have 3.
 * Therefore, you can't travel around the circuit once no matter where you
 * start.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == gas.length == cost.length
 * 1 <= n <= 10^5
 * 0 <= gas[i], cost[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int kSize = gas.size();
        int total_gas = 0;
        int total_cost = 0;
        int curr_tank = 0;
        int start = 0;
        for (int i = 0; i < kSize; i++) {
            int curr_gas = gas.at(i);
            int curr_cost = cost.at(i);

            total_gas += curr_gas;
            total_cost += curr_cost;
            curr_tank += curr_gas - curr_cost;
            if (curr_tank < 0) {
                start = i + 1;
                curr_tank = 0;
            }
        }

        if (total_gas >= total_cost) {
            return start;
        } else {
            return -1;
        }
    }
};
// @lc code=end

