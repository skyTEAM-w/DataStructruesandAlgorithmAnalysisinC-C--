#include <iostream>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> m = {
            {')', '('},
            {']', '['},
            {'}', '{'}};
        stack<char> st;
        for (const auto &c : s)
        {
            if (m.count(c))
            {
                if (st.empty() || st.top() != m[c])
                {
                    return false;
                }
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        return st.empty();
    }
};

int main()
{
    Solution *solution = new Solution();
    cout << solution->isValid("(){}}{");
    return 0;
}