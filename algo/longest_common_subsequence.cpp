//
// Longest common subsequence (LCS)
//
// Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.
//
// https://leetcode.com/problems/longest-common-subsequence/solution/
//
// Algo: dp solution, save space by keeping previous row only
//
// Complexity: O(n*m) time, O(min(n, m)) space
//
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        if (s1.size() < s2.size())
            swap(s1, s2);

        vector<int> prev(s2.size() + 1), cur(s2.size() + 1);

        for(size_t i = 0; i < s1.size(); ++i) {
            for(size_t j = 0; j < s2.size(); ++j) {
                if(s1[i] == s2[j])
                    cur[j + 1] = prev[j] + 1;
                else
                    cur[j + 1] = max(prev[j + 1], cur[j]);
            }

            swap(cur, prev);
        }

        return prev.back();
    }
};