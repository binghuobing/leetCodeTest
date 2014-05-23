#include<stack>
#include<string>

using namespace std;

bool isValidParenthese(string s)
{
    stack<char> st;
    for (stack<char>::size_type i = 0; i < s.size(); i++)
    {
        char c = s[i];
        switch(c)
        {
        case '(':
        case '{':
        case '[':
            st.push(c);
            break;
        case ')':
            if (st.empty())
                return false;
            if ('(' == st.top())
                st.pop();
            else
                return false;
            break;
        case ']':
            if (st.empty())
                return false;
            if ('[' == st.top())
                st.pop();
            else
                return false;
            break;
        case '}':
            if (st.empty())
                return false;
            if ('{' == st.top())
                st.pop();
            else
                return false;
            break;
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}
