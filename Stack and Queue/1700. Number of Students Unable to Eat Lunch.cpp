// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/

class Solution
{
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches)
    {
        queue<int> q;
        stack<int> st;

        for(int i=0; i<students.size(); i++)
        {
            q.push(students[i]);
        }

        for(int i=sandwiches.size()-1; i>=0; i--)
        {
            st.push(sandwiches[i]);
        }

        int x=0;
        while(!st.empty())
        {
            if(q.front()==st.top())
            {
                q.pop();
                st.pop();
                x = 0;
            }
            else
            {
                if(x == q.size())
                {
                    return q.size();
                }
                int val = q.front();
                q.pop();
                q.push(val);

                x++;
            }
        }
        return 0;
    }
};
