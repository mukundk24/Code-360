#include <bits/stdc++.h>
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '+' || s[i] == '*' || s[i] == '-' || s[i] == '/')
            st.push(s[i]);
        else
        {
            if (s[i] == ')')
            {
                bool redundant = true;
                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '*' || top == '-' || top == '/')
                    {
                        redundant = false;
                    }
                    st.pop();
                }
                if (redundant)
                    return true;
                st.pop();
            }
        }
    }
    return false;
}
