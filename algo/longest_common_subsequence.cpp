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


// Same problem as above, just O(n*m) space for better understanding
//
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int> (s2.size() + 1, 0));
        for(size_t i = 1; i <= s1.size(); ++i) {
            for(size_t j = 1; j <= s2.size(); ++j) {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};


// https://leetcode.com/problems/longest-palindromic-subsequence
// Top-down dp on is more intuitive
// Alterntative is reverse string and find LCS with approach above.
//
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n));

        return lps(s, 0, n - 1, memo);
    }

    int lps(string s, int i, int j, vector<vector<int>> &memo) {
        if (i > j)
            return 0;

        if (i == j)
            return 1;

        if (memo[i][j] != 0)
            return memo[i][j];

        if (s[i] == s[j]) {
            memo[i][j] = lps(s, i + 1, j - 1, memo) + 2;
        } else {
            memo[i][j] = max(lps(s, i + 1, j, memo), lps(s, i, j - 1, memo));
        }
        return memo[i][j];
    }
};