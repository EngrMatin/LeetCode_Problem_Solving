// https://leetcode.com/problems/house-robber-ii/

class Solution
{
public:
    int rob(vector<int>& v)
    {
       int n = v.size();
       if(n == 1)
       {
           return v[0];
       }

       int dp1[n],dp2[n];
       dp1[0] = v[0];
       dp1[1] = max(v[0],v[1]);

       for(int i=2; i<n-1; i++)
       {
           dp1[i] = max(dp1[i-1], v[i]+dp1[i-2]);
       }

       dp2[0] = 0;
       dp2[1] = v[1];

       for(int i=2; i<n; i++)
       {
           dp2[i] = max(dp2[i-1], dp2[i-2]+v[i]);
       }

       return max(dp1[n-2], dp2[n-1]);
    }
};
