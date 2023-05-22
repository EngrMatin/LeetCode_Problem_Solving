// https://leetcode.com/problems/best-team-with-no-conflicts/

class Solution
{
public:

    int bestTeamScore(vector<int>& scores, vector<int>& ages)
    {
        int n=scores.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({scores[i],ages[i]});
        }

        sort(v.begin(), v.end());
        vector<vector<int>> dp(n, vector<int>(1010,-1));
        return helper(v, 0, 0, dp);
    }

    int helper(vector<pair<int,int>>&v, int i, int mx, vector<vector<int>>&dp)
    {
        if(i>=v.size())
        {
            return 0;
        }

        if(dp[i][mx]!=-1)
        {
            return dp[i][mx];
        }

        if(v[i].second>=mx)
        {
            int op1 = helper(v, i+1, mx, dp);
            int op2 = v[i].first + helper(v, i+1, v[i].second, dp);
            return dp[i][mx]=max(op1,op2);
        }
        else
        {
            return dp[i][mx]=helper(v, i+1, mx, dp);
        }
    }
};
