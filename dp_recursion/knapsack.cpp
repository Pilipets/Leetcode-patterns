// Knapsack/Rucksack Problem
//
// https://www.geeksforgeeks.org/introduction-to-knapsack-problem-its-types-and-how-to-solve-them/
// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/
//
// Problem: Given a bag with maximum weight capacity of W and a set of items, each having a weight
// and a value associated with it. Decide the number of each item to take in a collection such
// that the total weight is less than the capacity and the total value is maximized.
//
// Complexity:
// O(N * W) time because of memo
// O(N * W) memo + O(N) stack space
//
// Recursion + memo to return the value of a maximum profit
//
int knapSackRec(int W, int weight[], int profit[], int index, int** dp)
{
    if (index < 0)
        return 0;
    if (dp[index][W] != -1)
        return dp[index][W];
 
    if (weight[index] > W) {

        dp[index][W] = knapSackRec(W, weight, profit, index - 1, dp);
        return dp[index][W];
    }
    else {
        dp[index][W] = max(profit[index] + knapSackRec(W - weight[index], weight, profit, index - 1, dp),
            knapSackRec(W, weight, profit, index - 1, dp));
 
        return dp[index][W];
    }
}


// LC - https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/
//
class Solution {
    static constexpr int mod = 1000000007;

    int dpWays(int dp[301][301], int n, int x, int k)
    {
        if (n < 0) return 0;
        if (n == 0) return 1;
        
        if (pow(k, x) > n) return 0;

        if (dp[n][k] != -1)
            return dp[n][k];
        
        int res = (dpWays(dp, n - pow(k, x), x, k + 1) + dpWays(dp, n, x, k + 1)) % mod;
        return dp[n][k] = res;
    }
public:
    int numberOfWays(int n, int x) {
        int dp[301]{1};
        
        for (int a = 1, v; (v = pow(a, x)) <= n; ++a)
            for (int i = n; i >= v; --i)
                dp[i] = (dp[i] + dp[i - v]) % mod;

        return dp[n];
    }
};


// Bottom-up dp approach for 0/1 Knapsack Problem
//
// Returns the maximum value that can be put in a knapsack of capacity W
//
int knapSack(int W, int weight[], int profit[], int n)
{
    vector<vector<int> > dp(n + 1, vector<int>(W + 1));
 
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(profit[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}


// Space-optimized bottom-up dp
//
// If we start traversing the rows from right to left then it can be done with a single row only
//
int knapSack(int W, int weight[], int profit[], int n)
{
    vector<vector<int>> dp(W + 1, 0);
 
    for (int i = 0; i < n; i++)
        for (int w = W; w >= 0; --w)
            if (weight[i] <= w)
                dp[w] = max(profit[i] + dp[w - weight[i]], dp[w]);

    return dp[W];
}


// LC - https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/
//
int numberOfWays(int n, int x) {
    int dp[301]{1};
    
    for (int a = 1, v; (v = pow(a, x)) <= n; ++a)
        for (int i = n; i >= v; --i)
            dp[i] = (dp[i] + dp[i - v]) % mod;

    return dp[n];
}