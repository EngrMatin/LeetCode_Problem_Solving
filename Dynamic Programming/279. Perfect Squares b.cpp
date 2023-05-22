// https://leetcode.com/problems/perfect-squares/

class Solution
{
public:
    int numSquares(int n)
    {
        unordered_map<int, int> memo;
        return helper(n, memo);
    }

    int helper(int n, std::unordered_map<int, int>& memo)
    {
        int root = sqrt(n);
        if (root * root == n)
        {
            return 1;
        }

        if (memo.find(n) != memo.end())
        {
            return memo[n];
        }

        int minSquares = INT_MAX;

        for (int i = 1; i * i <= n; i++)
        {
            int squares = helper(n - i * i, memo);
            minSquares = min(minSquares, squares);
        }

        memo[n] = minSquares + 1;
        return minSquares + 1;
    }
};
