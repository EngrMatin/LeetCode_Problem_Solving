// https://leetcode.com/problems/make-the-string-great/

class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;

        for(char c:s)
        {
            if(st.empty())
            {
                st.push(c);
                continue;
            }

            if(c>='a' && c<='z')
            {
                char x = st.top();
                if(x>='A' && x<='Z' && x+32==c)
                {
                    st.pop();
                }
                else
                {
                    st.push(c);
                }
            }
            else if(c>='A' && c<='Z')
            {
                char x = st.top();
                if(x>='a' && x<='z' && x-32==c)
                {
                    st.pop();
                }
                else
                {
                    st.push(c);
                }
            }
        }

        string ans = "";
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
