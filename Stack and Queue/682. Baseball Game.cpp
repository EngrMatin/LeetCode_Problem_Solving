// https://leetcode.com/problems/baseball-game/

class Solution
{
public:
    int convertToDecimal(string s)
    {
        int sum=0, locationValue = 1;

        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i] == '-')
            {
                break;
            }

            int digit = s[i]-'0';
            sum += (digit*locationValue);
            locationValue *= 10;
        }

        if(s[0] == '-')
        {
            return -sum;
        }
        else
        {
            return sum;
        }
    }

    int calPoints(vector<string>& ops)
    {
        stack<int> st;

        for(string s:ops)
        {
            if(s == "+")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x+y);
            }
            else if(s == "D")
            {
                st.push(st.top()*2);
            }
            else if(s == "C")
            {
                st.pop();
            }
            else
            {
                int val = convertToDecimal(s);
                st.push(val);
            }
        }

        int sum = 0;
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};
