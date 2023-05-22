// https://leetcode.com/problems/tallest-billboard/

class Solution
{
public:
    vector<unordered_map<int,int>> dp;
    int tallestBillboard(vector<int>& rods)
    {
        dp.assign(21,{});
        return helper(0, rods, 0);
    }

    int helper(int i, vector<int>& v, int diff)
    {
        if(i==v.size())
        {
            if(diff==0)
            {
                return 0;
            }
            return INT_MIN;
        }

        if(dp[i].find(diff)!=dp[i].end())
        {
            return dp[i][diff];
        }

        int x = helper(i+1, v, diff);
        int y = v[i] + helper(i+1, v, diff+v[i]);
        int z = helper(i+1, v, diff-v[i]);

        return dp[i][diff] = max({x,y,z});
    }
};
