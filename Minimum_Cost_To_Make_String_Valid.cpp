#include <bits/stdc++.h>
int findMinimumCost(string str)
{
    if (str.length() % 2 != 0)
        return -1;
    int clb = 0, opb = 0;
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
            st.push('{');
        else
        {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
                st.push(str[i]);
        }
    }
    while (!st.empty())
    {
        if (st.top() == '{')
            opb++;
        else
            clb++;
        st.pop();
    }
    return (opb + 1) / 2 + (clb + 1) / 2;
}