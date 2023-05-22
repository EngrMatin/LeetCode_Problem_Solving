// https://leetcode.com/problems/trapping-rain-water/description/

class Solution
{
public:
    int trap(vector<int>& heights)
    {
        int left = 0, right = heights.size()-1;
        int leftMax = 0, rightMax = 0, ans = 0;
        while(left <= right)
        {
            if(heights[left] <= heights[right])
            {
                if(heights[left] >= leftMax)
                {
                    leftMax = heights[left];
                }
                else
                {
                    ans += (leftMax - heights[left]);
                }
                left++;
            }
            else
            {
                if(heights[right] >= rightMax)
                {
                    rightMax = heights[right];
                }
                else
                {
                    ans += (rightMax - heights[right]);
                }
                right--;
            }
        }
        return ans;
    }
};
