// https://leetcode.com/problems/first-missing-positive/

class Solution
{
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int n = nums.size(), i;
        for(auto &i: nums)
        {
            if(i<=0||i>n)
            {
                i = n+1;
            }
        }

        for(auto &i: nums)
        {
            if(abs(i) == n+1 || nums[abs(i)-1] < 0) continue;
            nums[abs(i)-1] *= -1;
        }

        for(i = 1; i <= n; i++)
        {
            if(nums[i-1] > 0) return i;
        }

        return i;
    }
};
