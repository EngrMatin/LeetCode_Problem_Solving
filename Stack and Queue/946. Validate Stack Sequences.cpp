// https://leetcode.com/problems/validate-stack-sequences/

class Solution
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        int k = 0;
        stack<int> st;

        for(int a:pushed)
        {
            st.push(a);

            while(!st.empty() && st.top() == popped[k])
            {
                k++;
                st.pop();
            }
        }

        return st.empty();
    }
};
