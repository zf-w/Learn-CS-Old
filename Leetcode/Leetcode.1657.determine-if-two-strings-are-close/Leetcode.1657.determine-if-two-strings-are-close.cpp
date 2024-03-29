/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 *
 * https://leetcode.com/problems/determine-if-two-strings-are-close/description/
 *
 * algorithms
 * Medium (54.33%)
 * Likes:    809
 * Dislikes: 47
 * Total Accepted:    43.4K
 * Total Submissions: 80.2K
 * Testcase Example:  '"abc"\n"bca"'
 *
 * Two strings are considered close if you can attain one from the other using
 * the following operations:
 * 
 * 
 * Operation 1: Swap any two existing characters.
 * 
 * 
 * For example, abcde -> aecdb
 * 
 * 
 * Operation 2: Transform every occurrence of one existing character into
 * another existing character, and do the same with the other
 * character.
 * 
 * For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into
 * a's)
 * 
 * 
 * 
 * 
 * You can use the operations on either string as many times as necessary.
 * 
 * Given two strings, word1 and word2, return true if word1 and word2 are
 * close, and false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "abc", word2 = "bca"
 * Output: true
 * Explanation: You can attain word2 from word1 in 2 operations.
 * Apply Operation 1: "abc" -> "acb"
 * Apply Operation 1: "acb" -> "bca"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "a", word2 = "aa"
 * Output: false
 * Explanation: It is impossible to attain word2 from word1, or vice versa, in
 * any number of operations.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: word1 = "cabbba", word2 = "abbccc"
 * Output: true
 * Explanation: You can attain word2 from word1 in 3 operations.
 * Apply Operation 1: "cabbba" -> "caabbb"
 * Apply Operation 2: "caabbb" -> "baaccc"
 * Apply Operation 2: "baaccc" -> "abbccc"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word1.length, word2.length <= 10^5
 * word1 and word2 contain only lowercase English letters.
 * 
 * 
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> count_a(26, 0);
        vector<int> count_b(26, 0);
        const int kLength = word1.size();
        if (kLength != word2.size()) {
            return false;
        }

        for (int i = 0; i < kLength; i++) {
            count_a.at(word1.at(i) - 'a') += 1;
            
        }

        for (int i = 0; i < kLength; i++) {
            if (count_a.at(word2.at(i) - 'a') > 0) {
                count_b.at(word2.at(i) - 'a') += 1;
            } else {
                return false;
            }
        }

        sort(count_a.begin(), count_a.end());
        sort(count_b.begin(), count_b.end());

        for (int i = 0; i < 26; i++) {
            if (count_a.at(i) != count_b.at(i)) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

