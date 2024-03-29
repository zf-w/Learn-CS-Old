/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 *
 * https://leetcode.com/problems/find-the-town-judge/description/
 *
 * algorithms
 * Easy (49.53%)
 * Likes:    4273
 * Dislikes: 317
 * Total Accepted:    325.9K
 * Total Submissions: 662.1K
 * Testcase Example:  '2\n[[1,2]]'
 *
 * In a town, there are n people labeled from 1 to n. There is a rumor that one
 * of these people is secretly the town judge.
 * 
 * If the town judge exists, then:
 * 
 * 
 * The town judge trusts nobody.
 * Everybody (except for the town judge) trusts the town judge.
 * There is exactly one person that satisfies properties 1 and 2.
 * 
 * 
 * You are given an array trust where trust[i] = [ai, bi] representing that the
 * person labeled ai trusts the person labeled bi.
 * 
 * Return the label of the town judge if the town judge exists and can be
 * identified, or return -1 otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 2, trust = [[1,2]]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3, trust = [[1,3],[2,3]]
 * Output: 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 3, trust = [[1,3],[2,3],[3,1]]
 * Output: -1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 1000
 * 0 <= trust.length <= 10^4
 * trust[i].length == 2
 * All the pairs of trust are unique.
 * ai != bi
 * 1 <= ai, bi <= n
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mp[1001];
    int findJudge(int n, vector<vector<int>>& trusts) {
        memset(mp, 0, sizeof(mp));
        const int kSize = n;
        for (vector<int>& trust : trusts) {
            int a = trust.at(0);
            int b = trust.at(1);
            mp[b] += 1;
            mp[a] -= 1;
        }
        for (int i = 1; i <= kSize; i++) {
            if (mp[i] == kSize - 1) {
                return i;
            }
        }
        return -1;
    }
    //3\n[[1,3],[2,3],[3,1]]
    //2\n[[1,2]]
};
// @lc code=end

